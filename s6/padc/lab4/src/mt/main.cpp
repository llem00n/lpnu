#define _CRT_SECURE_NO_WARNINGS
#include <mpi.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstdint>
#include <chrono>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define ENABLE_LOG 0

#define N1 101
#define N2 217
#define N3 220

#define SUB_A_ROWS(n) (n < 3 ? 12 : 13)
#define SUB_A_COLS(n) N2

#define SUB_B_ROWS(n) N2
#define SUB_B_COLS(n) (n < 4 ? 27 : 28)

#define MATRIX_A 0
#define MATRIX_B 1

#define MATRIX_BUFFER_SIZE 1048576

#if ENABLE_LOG
  #define FLOG(file, fmt, ...) fprintf(file, fmt, ##__VA_ARGS__); fflush(file)
  #define LOG(fmt, ...) FLOG(stdout, fmt, ##__VA_ARGS__)
#else
  #define LOG(fmt, ...)
  #define FLOG(fmt, ...)
#endif

#define TAG_SUB_A_SIZE 1
#define TAG_SUB_B_SIZEPOS 2
#define TAG_SUB_A 3
#define TAG_SUB_B 4
#define TAG_SUB_C_SIZEPOS 5
#define TAG_SUB_C 6

int rank;

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

typedef struct mposyx {
  int32_t y;
  int32_t x;
} mposxy_t;

typedef struct msizepos {
  msize_t size;
  mpos_t pos;
  mposxy_t posyx;
} msizepos_t;

int run();

int main(int argc, char **argv) {
  MPI_Init(&argc, &argv);
  int size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if (rank == 0 && size != 9) {
    printf("It is required to run this program with 9 processes\n");
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  fflush(stdout);
  int code = run();

  MPI_Finalize();
  return code;
}

int _run_0();
int _run_other();

int run() {
  if (rank == 0) {
    return _run_0();
  } else {
    return _run_other();
  }
}

int get_mode();
void fill_matrix(double *m, int matrix, int mode);
void multiply(double *A, double *B, double *C, int n1, int n2, int n3);
void get_submatrix(double *m, double *sub_m, msize_t matsize, mpos_t pos, msize_t size);
void set_submatrix(double *m, double *sub_m, msize_t matsize, mpos_t pos, msize_t size);
int sprtinf_matrix(char *buffer, int buffer_size, double *m, msize_t size);

int get_to(int rank);
int get_from(int rank);

int _run_0() {
  FILE *out_0 = fopen("out_0.txt", "w");
  FILE *result = fopen("result.txt", "w");

  if (out_0 == NULL || result == NULL) {
    printf("Failed to open output files\n");
    MPI_Abort(MPI_COMM_WORLD, 1);
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

  auto start = std::chrono::high_resolution_clock::now();

  /* Send SUB As and Bs to all processes */
  for (int i = 0; i < 8; i++) {
    LOG("[%d]: Sending SUB A and SUB B to %d\n", 0, i + 1);

    msize sub_a_size = {SUB_A_ROWS(i), SUB_A_COLS(i)};
    msize sub_b_size = {SUB_B_ROWS(i), SUB_B_COLS(i)};
    
    double *sub_a = new double[sub_a_size.total()];
    double *sub_b = new double[sub_b_size.total()];
    get_submatrix(A, sub_a, {N1, N2}, sub_a_pos, sub_a_size);
    get_submatrix(B, sub_b, {N2, N3}, sub_b_pos, sub_b_size);

    msizepos sub_b_sizepos = {sub_b_size, sub_b_pos, {0, i}};

    MPI_Send(&sub_a_size, sizeof(msize_t), MPI_BYTE, i + 1, TAG_SUB_A_SIZE, MPI_COMM_WORLD);
    MPI_Send(&sub_b_sizepos, sizeof(msizepos_t), MPI_BYTE, i + 1, TAG_SUB_B_SIZEPOS, MPI_COMM_WORLD);

    LOG("[%d]: Sent SUB A(%d) size and SUB B(%d) size to %d\n", 0, i, i, i + 1);

    MPI_Send(sub_a, sub_a_size.total(), MPI_DOUBLE, i + 1, TAG_SUB_A, MPI_COMM_WORLD);
    MPI_Send(sub_b, sub_b_size.total(), MPI_DOUBLE, i + 1, TAG_SUB_B, MPI_COMM_WORLD);

    LOG("[%d]: Sent SUB A(%d) and SUB B(%d) to %d\n", 0, i, i, i + 1);

    delete[] sub_a;
    delete[] sub_b;

    sub_a_pos.row += sub_a_size.rows;
    sub_b_pos.col += sub_b_size.cols;
  }

  LOG("[%d]: Sent all SUB As and SUB Bs\n", 0);

  int from = get_from(0);
  int to = get_to(0);

  /* Loop through all steps */
  for (int i = 0; i < 8; i++) {
    /* Receive SUB Cs from all processes */
    for (int j = 1; j <= 8; j++) {
      LOG("[%d]: Receiving SUB C size and position from %d\n", 0, j);

      msizepos_t sub_c_sizepos;
      MPI_Recv(&sub_c_sizepos, sizeof(msizepos_t), MPI_BYTE, j, TAG_SUB_C_SIZEPOS, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

      LOG("[%d]: Received SUB C size and position from %d\n", 0, j);

      double *sub_c = new double[sub_c_sizepos.size.total()];
      MPI_Recv(sub_c, sub_c_sizepos.size.total(), MPI_DOUBLE, j, TAG_SUB_C, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      
      LOG("[%d]: Received SUB C from %d\n", 0, j);

      char *buffer = new char[MATRIX_BUFFER_SIZE];
      int offset = sprtinf_matrix(buffer, MATRIX_BUFFER_SIZE, sub_c, sub_c_sizepos.size);
      if (offset >= MATRIX_BUFFER_SIZE) {
        printf("Matrix is too large to be printed\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
        return 1;
      }
      FLOG(out_0, "SUB C(%d;%d) [%d;%d]:\n%s\n", sub_c_sizepos.pos.row, sub_c_sizepos.pos.col, sub_c_sizepos.size.rows, sub_c_sizepos.size.cols, buffer);
      delete[] buffer;

      set_submatrix(C, sub_c, {N1, N3}, sub_c_sizepos.pos, sub_c_sizepos.size);
      delete[] sub_c;
    }

    /* Receive SUB B from the from process */
    LOG("[%d]: Receiving SUB B(%d) from %d\n", 0, i, from);

    msizepos_t sub_b_sizepos;
    MPI_Recv(&sub_b_sizepos, sizeof(msizepos_t), MPI_BYTE, from, TAG_SUB_B_SIZEPOS, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    LOG("[%d]: Received SUB B(%d) size from %d\n", 0, i, from);

    double *sub_b = new double[sub_b_sizepos.size.total()];
    MPI_Recv(sub_b, sub_b_sizepos.size.total(), MPI_DOUBLE, from, TAG_SUB_B, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    LOG("[%d]: Received SUB B(%d) from %d\n", 0, i, from);

    /* Send SUB B to the to process */
    LOG("[%d]: Sending SUB B(%d) to %d\n", 0, i, to);

    MPI_Send(&sub_b_sizepos, sizeof(msizepos_t), MPI_BYTE, to, TAG_SUB_B_SIZEPOS, MPI_COMM_WORLD);
    MPI_Send(sub_b, sub_b_sizepos.size.total(), MPI_DOUBLE, to, TAG_SUB_B, MPI_COMM_WORLD);

    LOG("[%d]: Sent SUB B(%d) to %d\n", 0, i, to);

    delete[] sub_b;
  }

  LOG("[%d]: Calculated C\n", 0);

  auto end = std::chrono::high_resolution_clock::now();
  auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
  auto duration_ms = duration_ns / 1000000;
  printf("Time taken: %lld ns (%lld ms)\n", duration_ns, duration_ms);

  char *buffer = new char[MATRIX_BUFFER_SIZE];
  int offset = sprtinf_matrix(buffer, MATRIX_BUFFER_SIZE, A, {N1, N2});
  if (offset >= MATRIX_BUFFER_SIZE) {
    printf("Matrix A is too large to be printed\n");
    MPI_Abort(MPI_COMM_WORLD, 1);
    return 1;
  }
  FLOG(result, "A:\n%s\n\n", buffer);

  offset = sprtinf_matrix(buffer, MATRIX_BUFFER_SIZE, B, {N2, N3});
  if (offset >= MATRIX_BUFFER_SIZE) {
    printf("Matrix B is too large to be printed\n");
    MPI_Abort(MPI_COMM_WORLD, 1);
    return 1;
  }
  FLOG(result, "B:\n%s\\nn", buffer);

  offset = sprtinf_matrix(buffer, MATRIX_BUFFER_SIZE, C, {N1, N3});
  if (offset >= MATRIX_BUFFER_SIZE) {
    printf("Matrix C is too large to be printed\n");
    MPI_Abort(MPI_COMM_WORLD, 1);
    return 1;
  }

  FLOG(result, "C:\n%s\n", buffer);
  delete[] buffer;

  return 0;
}

int _run_other() {
  LOG("[%d]: Started\n", rank);

  char filename[32];
  snprintf(filename, 32, "out_%d.txt", rank);
  FILE *out = fopen(filename, "w");

  if (out == NULL) {
    printf("Failed to open output file\n");
    MPI_Abort(MPI_COMM_WORLD, 1);
    return 1;
  }

  /* Receive SUB A and SUB B */
  msize_t sub_a_size;
  msizepos_t sub_b_sizepos;

  LOG("[%d]: Receiving SUB A size\n", rank);
  MPI_Recv(&sub_a_size, sizeof(msize_t), MPI_BYTE, 0, TAG_SUB_A_SIZE, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

  LOG("[%d]: Received SUB A size\n[%d]: Receiving SUB B size\n", rank, rank);
  MPI_Recv(&sub_b_sizepos, sizeof(msizepos_t), MPI_BYTE, 0, TAG_SUB_B_SIZEPOS, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

  LOG("[%d]: Received SUB B size\n[%d]: Receiving SUB A\n", rank, rank);
  double *sub_a = new double[sub_a_size.total()];
  MPI_Recv(sub_a, sub_a_size.total(), MPI_DOUBLE, 0, TAG_SUB_A, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

  LOG("[%d]: Received SUB A\n[%d]: Receiving SUB B\n", rank, rank);
  double *sub_b = new double[sub_b_sizepos.size.total()];
  MPI_Recv(sub_b, sub_b_sizepos.size.total(), MPI_DOUBLE, 0, TAG_SUB_B, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

  LOG("[%d]: Received SUB B\n", rank);

  /* Calculate SUB C y pos */
  msizepos_t sub_c_sizepos;
  sub_c_sizepos.pos.row = (MIN(MAX(rank - 1, 0), 3)) * 12 + (MAX(rank - 4, 0)) * 13;
  LOG("[%d]: Calculated SUB C y pos: %d\n", rank, sub_c_sizepos.pos.row);

  int to = get_to(rank);
  int from = get_from(rank);

  /* Loop through all steps */
  for (int i = 0; i < 8; i++) {
    int x = sub_b_sizepos.posyx.x;

    LOG("[%d]: x: %d, i: %d\n", rank, x, i);

    /* Calculate SUB C */
    double *sub_c = new double[sub_a_size.rows * sub_b_sizepos.size.cols];
    multiply(sub_a, sub_b, sub_c, sub_a_size.rows, sub_a_size.cols, sub_b_sizepos.size.cols);
    sub_c_sizepos.size = {sub_a_size.rows, sub_b_sizepos.size.cols};
    sub_c_sizepos.pos.col = (MIN(x, 4)) * 27 + (MAX(x - 4, 0)) * 28;
    LOG("[%d]: Calculated SUB C x(%d) pos: %d\n", rank, x, sub_c_sizepos.pos.col);

    /* Send SUB C */
    LOG("[%d]: Sending SUB C size and position to 0\n", rank);
    MPI_Send(&sub_c_sizepos, sizeof(msizepos_t), MPI_BYTE, 0, TAG_SUB_C_SIZEPOS, MPI_COMM_WORLD);

    LOG("[%d]: Sent SUB C size and position to 0\n[%d]: Sending SUB C to 0\n", rank, rank);
    MPI_Send(sub_c, sub_c_sizepos.size.total(), MPI_DOUBLE, 0, TAG_SUB_C, MPI_COMM_WORLD);

    LOG("[%d]: Sent SUB C to 0\n", rank);

    char *buffer = new char[MATRIX_BUFFER_SIZE];
    int offset = sprtinf_matrix(buffer, MATRIX_BUFFER_SIZE, sub_c, sub_c_sizepos.size);
    if (offset >= MATRIX_BUFFER_SIZE) {
      printf("Matrix is too large to be printed\n");
      MPI_Abort(MPI_COMM_WORLD, 1);
      return 1;
    }

    FLOG(out, "SUB C(%d;%d) [%d;%d]:\n%s\n", sub_c_sizepos.pos.row, sub_c_sizepos.pos.col, sub_c_sizepos.size.rows, sub_c_sizepos.size.cols, buffer);

    delete[] sub_c;

    /* Send SUB B to the to process */
    LOG("[%d]: Sending SUB B to %d\n", rank, to);
    MPI_Send(&sub_b_sizepos, sizeof(msizepos_t), MPI_BYTE, to, TAG_SUB_B_SIZEPOS, MPI_COMM_WORLD);

    LOG("[%d]: Sent SUB B sizepos to %d\n[%d]: Sending SUB B to %d\n", rank, to, rank, to);
    MPI_Send(sub_b, sub_b_sizepos.size.total(), MPI_DOUBLE, to, TAG_SUB_B, MPI_COMM_WORLD);

    LOG("[%d]: Sent SUB B to %d\n[%d]: Receiving SUB B sizepos from %d\n", rank, to, rank, from);
    delete[] sub_b;

    /* Receive SUB B */
    MPI_Recv(&sub_b_sizepos, sizeof(msizepos_t), MPI_BYTE, from, TAG_SUB_B_SIZEPOS, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    LOG("[%d]: Received SUB B sizepos from %d\n[%d]: Receiving SUB B from %d\n", rank, from, rank, from);
    sub_b = new double[sub_b_sizepos.size.total()];
    MPI_Recv(sub_b, sub_b_sizepos.size.total(), MPI_DOUBLE, from, TAG_SUB_B, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    LOG("[%d]: Received SUB B from %d\n", rank, from);
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

void get_submatrix(double *m, double *sub_m, msize_t matsize, mpos_t pos, msize_t size) {
  for (int i = 0; i < size.rows; i++) {
    for (int j = 0; j < size.cols; j++) {
      sub_m[i * size.cols + j] = m[(pos.row + i) * matsize.cols + pos.col + j];
    }
  }
}

void set_submatrix(double *m, double *sub_m, msize_t matsize, mpos_t pos, msize_t size) {
  for (int i = 0; i < size.rows; i++) {
    for (int j = 0; j < size.cols; j++) {
      m[(pos.row + i) * matsize.cols + pos.col + j] = sub_m[i * size.cols + j];
    }
  }
}

int get_to(int rank) {
  int tos[] = {8, 5, 3, 4, 7, 0, 2, 1, 6};
  return tos[rank];
}

int get_from(int rank) {
  int froms[] = {5, 7, 6, 2, 3, 1, 8, 4, 0};
  return froms[rank];
}

int sprtinf_matrix(char *buffer, int buffer_size, double *m, msize_t size) {
  int offset = 0;
  for (int i = 0; i < size.rows; i++) {
    for (int j = 0; j < size.cols; j++) {
      offset += snprintf(buffer + offset, buffer_size - offset, "%f ", m[i * size.cols + j]);
      if (offset >= buffer_size) {
        return offset;
      }
    }
    offset += snprintf(buffer + offset, buffer_size - offset, "\n");
    if (offset >= buffer_size) {
      return offset;
    }
  }

  return offset;
}