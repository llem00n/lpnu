#define _CRT_SECURE_NO_WARNINGS
#include <mpi.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstdint>

#define ENABLE_LOG 1

#define N1 101
#define N2 217
#define N3 220

#define SUB_A_ROWS(n) (n < 3 ? 12 : 13)
#define SUB_A_COLS(n) N2

#define SUB_B_ROWS(n) N2
#define SUB_B_COLS(n) (n < 4 ? 27 : 28)

#define MATRIX_A 0
#define MATRIX_B 1

#define MATRIX_BUFFER_SIZE 32768

#if ENABLE_LOG
  #define FLOG(file, fmt, ...) fprintf(file, fmt, ##__VA_ARGS__); fflush(file)
  #define LOG(fmt, ...) FLOG(stdout, fmt, ##__VA_ARGS__)
#else
  #define LOG(fmt, ...)
  #define FLOG(fmt, ...)
#endif

typedef struct msize {
  int32_t rows;
  int32_t cols;
  
  int32_t total() {
    return rows * cols;
  }
} msize_t;

typedef struct mpos {
  int32_t row;
  int32_t col;
} mpos_t;

typedef struct msizepos {
  msize_t size;
  mpos_t pos;
} msizepos_t;

int run(int rank);

int main(int argc, char **argv) {
  MPI_Init(&argc, &argv);
  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if (rank == 0 && size != 9) {
    printf("It is required to run this program with 9 processes\n");
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  fflush(stdout);
  int code = run(rank);

  MPI_Finalize();
  return code;
}

int _run_0();
int _run_other(int rank);

int run(int rank) {
  if (rank == 0) {
    return _run_0();
  } else {
    return _run_other(rank);
  }
}

int get_mode();
void fill_matrix(double *m, int matrix, int mode);
void multiply(double *A, double *B, double *C, int n1, int n2, int n3);
void get_submatrix(double *m, double *sub_m, mpos_t pos, msize_t size);
void set_submatrix(double *m, double *sub_m, mpos_t pos, msize_t size);
void sprtinf_matrix(char *buffer, int buffer_size, double *m, msize_t size);\
void update_sub_c_pos(mpos_t *c_pos);

int get_to(int rank);
int get_from(int rank);

int mpi_send(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);
int mpi_recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status);

int _run_0() {
  FILE *out_1 = fopen("out_1.txt", "w");
  FILE *result = fopen("result.txt", "w");

  if (out_1 == NULL || result == NULL) {
    printf("Failed to open output files\n");
    return 1;
  }

  srand(static_cast<unsigned>(time(NULL)));
  
  int mode = get_mode();
  double *A = new double[N1 * N2];
  fill_matrix(A, MATRIX_A, mode);
  double *B = new double[N2 * N3];
  fill_matrix(B, MATRIX_B, mode);
  double *C = new double[N1 * N3];

  mpos_t sub_a_pos = {0, 0};
  mpos_t sub_b_pos = {0, 0};

  for (int i = 0; i < 8; i++) {
    LOG("[%d]: Sending SUB A and SUB B to %d\n", 0, i + 1);

    msize sub_a_size = {SUB_A_ROWS(i), SUB_A_COLS(i)};
    msize sub_b_size = {SUB_B_ROWS(i), SUB_B_COLS(i)};
    
    double *sub_a = new double[sub_a_size.total()];
    double *sub_b = new double[sub_b_size.total()];
    get_submatrix(A, sub_a, sub_a_pos, sub_a_size);
    get_submatrix(B, sub_b, sub_b_pos, sub_b_size);

    sub_a_pos.row += sub_a_size.rows;
    sub_b_pos.col += sub_b_size.cols;


    MPI_Send(&sub_a_size, sizeof(msize_t), MPI_BYTE, i + 1, 0, MPI_COMM_WORLD);
    MPI_Send(&sub_b_size, sizeof(msize_t), MPI_BYTE, i + 1, 0, MPI_COMM_WORLD);

    LOG("[%d]: Sent SUB A(%d) and SUB B(%d) to %d\n", 0, i, i, i + 1);

    MPI_Send(sub_a, sub_a_size.total(), MPI_DOUBLE, i + 1, 0, MPI_COMM_WORLD);
    MPI_Send(sub_b, sub_b_size.total(), MPI_DOUBLE, i + 1, 0, MPI_COMM_WORLD);

    LOG("[%d]: Sent SUB A(%d) and SUB B(%d) to %d\n", 0, i, i, i + 1);

    delete[] sub_a;
    delete[] sub_b;
  }

  LOG("[%d]: Sent all SUB As and SUB Bs\n", 0);

  int from = get_from(0);
  int to = get_to(0);

  LOG("[%d]: Receiving SUB C(%d;%d) from %d\n", 0, from - 1, from - 1, from);
  msizepos_t c_sizepos;
  MPI_Recv(&c_sizepos, sizeof(msizepos_t), MPI_BYTE, from, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  update_sub_c_pos(&c_sizepos.pos);
  double *sub_c = new double[c_sizepos.size.total()];
  MPI_Recv(sub_c, c_sizepos.size.total(), MPI_DOUBLE, from, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  set_submatrix(C, sub_c, c_sizepos.pos, c_sizepos.size);
  delete[] sub_c;
  LOG("[%d]: Received SUB C(%d;%d) from %d\n", 0, c_sizepos.pos.row, c_sizepos.pos.col, from);

  for (int i = 0; i < 8; i++) {
    msize_t b_sub_size;

    LOG("[%d]: b_sub_size address: %p\n", 0, &b_sub_size);

    LOG("[%d]: Receiving SUB B from %d\n", 0, from);
    MPI_Recv(&b_sub_size, 16, MPI_BYTE, from, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    LOG("[%d]: Received SUB B size from %d (values are: %d, %d)\n", 0, from, b_sub_size.rows, b_sub_size.cols);
    double *b_sub = new double[b_sub_size.total()];
    LOG("[%d]: b_sub address: %p\n", 0, b_sub);
    MPI_Recv(b_sub, b_sub_size.total(), MPI_DOUBLE, from, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    LOG("[%d]: Received SUB B from %d\n", 0, from);

    MPI_Send(&b_sub_size, sizeof(msize_t), MPI_BYTE, to, 0, MPI_COMM_WORLD);
    MPI_Send(b_sub, b_sub_size.total(), MPI_DOUBLE, to, 0, MPI_COMM_WORLD);
    delete[] b_sub;

    LOG("[%d]: Sent SUB B to %d\n", 0, to);

    msizepos_t c_sizepos;
    MPI_Recv(&c_sizepos, sizeof(msizepos_t), MPI_BYTE, i + 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    update_sub_c_pos(&c_sizepos.pos);
    double *sub_c = new double[c_sizepos.size.total()];
    MPI_Recv(sub_c, c_sizepos.size.total(), MPI_DOUBLE, i + 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    set_submatrix(C, sub_c, c_sizepos.pos, c_sizepos.size);

    LOG("[%d]: Received SUB C(%d;%d) from %d\n", 0, c_sizepos.pos.row, c_sizepos.pos.col, i + 1);
  }

  char buffer[MATRIX_BUFFER_SIZE];
  sprtinf_matrix(buffer, MATRIX_BUFFER_SIZE, C, {N1, N3});
  FLOG(result, "C:\n%s\n", buffer);

  return 0;
}

int _run_other(int rank) {
  LOG("[%d]: Started\n", rank);

  char filename[32];
  snprintf(filename, 32, "out_%d.txt", rank);
  FILE *out = fopen(filename, "w");

  if (out == NULL) {
    printf("Failed to open output file\n");
    return 1;
  }

  msize_t sub_a_size, sub_b_size;
  mpos_t sub_c_pos = {rank - 1, rank - 1};
  msizepos_t c_sizepos;
  MPI_Recv(&sub_a_size, sizeof(msize_t), MPI_BYTE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  MPI_Recv(&sub_b_size, sizeof(msize_t), MPI_BYTE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

  LOG("[%d]: Received SUB A(%d) and SUB B(%d) sizes\n", rank, rank - 1, rank - 1);

  double *sub_a = new double[sub_a_size.total()];
  double *sub_b = new double[sub_b_size.total()];

  MPI_Recv(sub_a, sub_a_size.total(), MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  MPI_Recv(sub_b, sub_b_size.total(), MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

  LOG("[%d]: Received SUB A(%d) and SUB B(%d)\n", rank, rank - 1, rank - 1);

  double *sub_c = new double[sub_a_size.rows * sub_b_size.cols];
  multiply(sub_a, sub_b, sub_c, sub_a_size.rows, sub_a_size.cols, sub_b_size.cols);
  c_sizepos.size = {sub_a_size.rows, sub_b_size.cols};
  c_sizepos.pos = sub_c_pos;

  char buffer[MATRIX_BUFFER_SIZE];
  sprtinf_matrix(buffer, MATRIX_BUFFER_SIZE, sub_c, c_sizepos.size);
  FLOG(out, "SUB C(%d;%d):\n %s\n\n", sub_c_pos.row, sub_c_pos.col, buffer);

  LOG("[%d]: Sending SUB C(%d;%d) to %d\n", rank, sub_c_pos.row, sub_c_pos.col, get_to(rank));

  MPI_Send(&c_sizepos, sizeof(msizepos_t), MPI_BYTE, 0, 0, MPI_COMM_WORLD);
  MPI_Send(sub_c, sub_a_size.rows * sub_b_size.cols, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);

  LOG("[%d]: Sent SUB C(%d;%d) to %d\n", rank, c_sizepos.pos.row, c_sizepos.pos.col, 0);

  delete[] sub_b;
  delete[] sub_c;

  int from = get_from(rank);
  int to = get_to(rank);

  for (int i = 0; i < 7; i++) {
    int sub_c_pos_col_old = sub_c_pos.col;
    sub_c_pos.col = sub_c_pos.row + 1 % 8;

    LOG("[%d]: Sending SUB B(%d) to %d (values are: %d, %d)\n", rank, sub_c_pos_col_old, to, sub_b_size.rows, sub_b_size.cols);

    MPI_Send(&sub_b_size, sizeof(msize_t), MPI_BYTE, to, 0, MPI_COMM_WORLD);
    LOG("[%d]: Sent SUB B(%d) size to %d\n", rank, sub_c_pos_col_old, to);

    MPI_Send(sub_b, sub_b_size.total(), MPI_DOUBLE, to, 0, MPI_COMM_WORLD);
    delete[] sub_b;

    LOG("[%d]: Sent SUB B(%d) to %d\n", rank, sub_c_pos_col_old, to);

    LOG("[%d]: Receiving SUB B(%d) from %d\n", rank, sub_c_pos.col, from);

    MPI_Recv(&sub_b_size, sizeof(msize_t), MPI_BYTE, from, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    sub_b = new double[sub_b_size.total()];
    MPI_Recv(sub_b, sub_b_size.total(), MPI_DOUBLE, from, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    LOG("[%d]: Received SUB B(%d) from %d\n", rank, sub_c_pos.col, from);

    sub_c = new double[sub_a_size.rows * sub_b_size.cols];
    LOG("[%d]: Calculating SUB C(%d;%d), log values: %d, %d, %d\n", rank, sub_c_pos.row, sub_c_pos.col, sub_a_size.rows, sub_a_size.cols, sub_b_size.cols);
    sprtinf_matrix(buffer, MATRIX_BUFFER_SIZE, sub_b, sub_b_size);
    LOG("[%d]: Calcualting SUB C(%d;%d), SUB B(%d) values:\n%s\n", rank, sub_c_pos.row, sub_c_pos.col, sub_c_pos_col_old, buffer);
    multiply(sub_a, sub_b, sub_c, sub_a_size.rows, sub_a_size.cols, sub_b_size.cols);
    c_sizepos.size = {sub_a_size.rows, sub_b_size.cols};
    c_sizepos.pos = sub_c_pos;

    LOG("[%d]: Calculated SUB C(%d;%d)\n", rank, sub_c_pos.row, sub_c_pos.col);

    sprtinf_matrix(buffer, MATRIX_BUFFER_SIZE, sub_a, sub_a_size);
    FLOG(out, "SUB C(%d;%d):\n %s\n\n", sub_c_pos.row, sub_c_pos.col, buffer);

    LOG("[%d]: Sending SUB C(%d;%d) to %d\n", rank, c_sizepos.pos.row, c_sizepos.pos.col, 0);

    MPI_Send(&c_sizepos, sizeof(msizepos_t), MPI_BYTE, 0, 0, MPI_COMM_WORLD);
    MPI_Send(sub_c, sub_a_size.rows * sub_b_size.cols, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    delete[] sub_c;

    LOG("[%d]: Sent SUB C(%d;%d) to %d\n", rank, c_sizepos.pos.row, c_sizepos.pos.col, 0);
  }

  return 0;
}

int get_mode() {
  printf("Available modes:\n"
  "  1: A & B are filled with 1\n"
  "  2: A is filled with 1, B is filled with 3\n"
  "  3: A & B are filled with random numbers from 1 to 9\n"
  "  4: A is filled with random numbers from 10 to 99 multiplied by ±1\n"
  "  5: A is filled with random numbers from 100.0 to 9990.0\n"
  "(default: 1): ");
  fflush(stdout);
  int mode;
  scanf("%d", &mode);
  if (mode < 1 || mode > 5) {
    mode = 1;
  }

  return mode;
}

void fill_matrix(double *m, int matrix, int mode) {
  int rows = matrix == MATRIX_A ? N1 : N2;
  int cols = matrix == MATRIX_A ? N2 : N3;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      switch (mode) {
        case 1:
          m[i * cols + j] = 1.0;
          break;
        case 2:
          m[i * cols + j] = matrix == MATRIX_A ? 1.0 : 3.0;
          break;
        case 3:
          m[i * cols + j] = rand() % 9 + 1;
          break;
        case 4:
          m[i * cols + j] = (rand() % 90 + 10) * (rand() % 2 == 0 ? 1 : -1);
          break;
        case 5:
          m[i * cols + j] = (rand() % 9990 + 100) / 10.0;
          break;
        default:
          m[i * cols + j] = 0.0;
          break;
      }
    }
  }
}

void multiply(double *A, double *B, double *C, int n1, int n2, int n3) {
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < n3; j++) {
      C[i * n3 + j] = 0.0;
      for (int k = 0; k < n2; k++) {
        C[i * n3 + j] += A[i * n2 + k] * B[k * n3 + j];
      }
    }
  }
}

void get_submatrix(double *m, double *sub_m, mpos_t pos, msize_t size) {
  for (int i = 0; i < size.rows; i++) {
    for (int j = 0; j < size.cols; j++) {
      sub_m[i * size.cols + j] = m[(pos.row + i) * N2 + pos.col + j];
    }
  }
}

void set_submatrix(double *m, double *sub_m, mpos_t pos, msize_t size) {
  for (int i = 0; i < size.rows; i++) {
    for (int j = 0; j < size.cols; j++) {
      m[(pos.row + i) * N2 + pos.col + j] = sub_m[i * size.cols + j];
    }
  }
}

void update_sub_c_pos(mpos_t *c_pos) {
  mpos_t new_pos = *c_pos;

  for (int i = 0; i < c_pos->row; i++) {
    new_pos.row += SUB_A_ROWS(i);
  }

  for (int i = 0; i < c_pos->col; i++) {
    new_pos.col += SUB_B_COLS(i);
  }

  *c_pos = new_pos;
}

int get_to(int rank) {
  int tos[] = {8, 5, 3, 4, 7, 0, 2, 1, 6};
  return tos[rank];
}

int get_from(int rank) {
  int froms[] = {5, 7, 6, 2, 3, 1, 8, 4, 0};
  return froms[rank];
}

void sprtinf_matrix(char *buffer, int buffer_size, double *m, msize_t size) {
  int offset = 0;
  for (int i = 0; i < size.rows; i++) {
    for (int j = 0; j < size.cols; j++) {
      offset += snprintf(buffer + offset, buffer_size - offset, "%f ", m[i * size.cols + j]);
    }
    offset += snprintf(buffer + offset, buffer_size - offset, "\n");
  }
}

int mpi_send(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) {
  int code = MPI_Send(buf, count, datatype, dest, tag, comm);
  if (code != MPI_SUCCESS) {
    printf("MPI_Send failed with code %d\n", code);
    MPI_Abort(comm, code);
  }
  char ping = 0;
  code = MPI_Recv(&ping, 1, MPI_BYTE, dest, tag, comm, MPI_STATUS_IGNORE);
  if (code != MPI_SUCCESS || ping != 1) {
    printf("MPI_Recv ping failed with code %d\n", code);
    MPI_Abort(comm, code);
  }

  return code;
}

int mpi_recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status) {
  int code = MPI_Recv(buf, count, datatype, source, tag, comm, status);
  if (code != MPI_SUCCESS) {
    printf("MPI_Recv failed with code %d\n", code);
    MPI_Abort(comm, code);
  }
  char ping = 1;
  code = MPI_Send(&ping, 1, MPI_BYTE, source, tag, comm);
  if (code != MPI_SUCCESS) {
    printf("MPI_Send ping failed with code %d\n", code);
    MPI_Abort(comm, code);
  }

  return code;
}