#define _CRT_SECURE_NO_WARNINGS
#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <windows.h>

#define size1 300
#define size2 112
#define size3 214

	const int ROW1 = 37;
	const int ROW2 = 38;
	const int ROW1COUNT = 4;

	const int COLUMN1 = 28;
	const int COLUMN2 = 26;
	const int COLUMN1COUNT = 3;

	const int MAX_COLUMN_SIZE = (COLUMN1 > COLUMN2) ? COLUMN1 : COLUMN2;
	const int ANOTHER_COLUMN_SIZE_INDEX = COLUMN1 * COLUMN1COUNT;

	double** CreateMatrix(int m, int n)
	{
		double** a = (double**)malloc(m * sizeof(double*));
		for (int i = 0; i < m; i++)
			a[i] = (double*)malloc(n * sizeof(double));
		return a;
	}
	void DeleteMatrix(double** a, int m, int n)
	{
		for (int i = 0; i < m; i++)
			free(a[i]);
		free(a);
	}
	void FillMatrixA(double** a, int m, int n, int mode)
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if (mode == 1)
				{
					a[i][j] = 1;
				}
				else if (mode == 2)
				{
					a[i][j] = 1;
				}
				else if (mode == 3)
				{
					a[i][j] = 1 + (rand() % 9);
				}
				else if (mode == 4)
				{
					a[i][j] = (10 + (rand() % 90)) * (rand() % 2 == 0 ? 1 : -1);
				}
				else
				{
					a[i][j] = (100 + (rand() % 9900)) + (rand() / (double)RAND_MAX);
				}
			}
	}

	void FillMatrixB(double** a, int m, int n, int mode)
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if (mode == 1)
				{
					a[i][j] = 1;
				}
				else if (mode == 2)
				{
					a[i][j] = 3;
				}
				else if (mode == 3)
				{
					a[i][j] = 1 + (rand() % 9);
				}
				else if (mode == 4)
				{
					a[i][j] = (10 + (rand() % 90)) * (rand() % 2 == 0 ? 1 : -1);
				}
				else
				{
					a[i][j] = (100 + (rand() % 9900)) + (rand() / (double)RAND_MAX);
				}
			}
	}

	void PrintMatrixToFile(FILE * f, char* title, double** a, int m, int n)
	{
		fprintf(f, title);
		fprintf(f, "\n");
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				fprintf(f, "%.0f\t", a[i][j]);
			fprintf(f, "\n");
		}
		fprintf(f, "\n");
	}
	// c = a * b, a - [m][n], b - [n][k], c - [m][k]
	double** MultMatrix(double** c, double** a, double** b, int m, int n, int k)
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < k; j++)
			{
				c[i][j] = 0;
				for (int l = 0; l < n; l++)
					c[i][j] = c[i][j] + a[i][l] * b[l][j];
			}
		return c;
	}
	int main(int argc, char* argv[])
	{
		srand((unsigned int)time(NULL));
		MPI_Init(NULL, NULL);
		LARGE_INTEGER frequency, start, end;
		int rank, size;
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		MPI_Comm_size(MPI_COMM_WORLD, &size);
		if (size != 9)
		{
			printf("This program requires 9 processes !\n");
			fflush(stdout);
			MPI_Abort(MPI_COMM_WORLD, 1);
		}

		int i, j, k;
		int shift;
		int out;
		char SubMatrix[32];
		char fileName[32];

		if (rank == 0)
		{
			double** A = CreateMatrix(size1, size2);
			double** B = CreateMatrix(size2, size3);
			double** C = CreateMatrix(size1, size3);
			sprintf(fileName, "Results_0.txt");
			FILE* file = fopen(fileName, "w");
			if (file == NULL)
			{
				printf("\nError opening file. Check the path and permissions !\n");
				return 1;
			}
			printf("Output the results to the screen and to the file? 1 - yes, else -no : ");
			fflush(stdout);
			scanf("%d", &out);

			for (i = 1; i <= 8; i++)
				MPI_Send(&out, 1, MPI_INT, i, 0, MPI_COMM_WORLD);

			static int mode;
			printf("Available modes:\n");
			printf("1      fill A with 1, B with 1\n");
			printf("2      fill A with 1, B with 3\n");
			printf("3      fill with random ints from 1 to 9\n");
			printf("4      fill with random ints from (-)10 to (-)99\n");
			printf("5      fill with random doubles from 100 to 9999\n");
			printf("Select mode:\n");
			fflush(stdout);
			scanf("%d", &mode);

			// random input matrix A
			FillMatrixA(A, size1, size2, mode);
			PrintMatrixToFile(file, (char*)"Matrix A = ", A, size1, size2);
			// random input matrix B
			FillMatrixB(B, size2, size3, mode);
			PrintMatrixToFile(file, (char*)"Matrix B = ", B, size2, size3);
			QueryPerformanceFrequency(&frequency);
			QueryPerformanceCounter(&start);
			// розсилання підматриць А і В
			int A_rows;
			j = 0;
			int B_columns;
			int B_submatrix;
			shift = 0;


			for (i = 1; i <= 8; i++)
			{
				if (i <= ROW1COUNT)
					A_rows = ROW1;
				else
					A_rows = ROW2;
				if (out == 1)
				{
					printf("I am 0 process. Send SubMatrix A%d in size %d x 112 to %d process\n", i, A_rows, i);
					fflush(stdout);
				}
				MPI_Send(&A_rows, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
				for (k = 0; k < A_rows; k++, j++)
					MPI_Send(A[j], size2, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);

				if (i <= COLUMN1COUNT)
					B_columns = COLUMN1;
				else
					B_columns = COLUMN2;

				B_submatrix = i;
				if (out == 1)
				{
					printf("I am 0 process. Send SubMatrix B%d in size 112 x %d to %d process\n", B_submatrix, B_columns, i);
					fflush(stdout);
				}
				MPI_Send(&B_submatrix, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
				MPI_Send(&B_columns, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
				for (k = 0; k < size2; k++)
					MPI_Ssend((B[k] + shift), B_columns, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);

				shift += B_columns;
			}

			// отримання частини матриці С після першого кроку
			j = 0;
			shift = 0;
			for (i = 1; i <= 8; i++)
			{
				MPI_Recv(&A_rows, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&B_columns, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

				for (k = 0; k < A_rows; k++, j++)
					MPI_Recv((C[j] + shift), B_columns, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

				shift += B_columns;

				if (out == 1)
				{
					printf("I am 0 process. Received SubMatrix C%d%d from %d process\n", i, i, i);
					fflush(stdout);
				}
			}

			// буфер для отримання смуги матриці В від 1 процесу
			double** b_temp = CreateMatrix(size2, MAX_COLUMN_SIZE);
			for (i = 2; i <= 8; i++)
			{
				// отримання смуги матриці В від 8-го процесу
				MPI_Recv(&B_submatrix, 1, MPI_INT, 8, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&B_columns, 1, MPI_INT, 8, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				for (j = 0; j < size2; j++)
					MPI_Recv(b_temp[j], B_columns, MPI_DOUBLE, 8, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				if (out == 1)
				{
					printf("I am 0 process. Received SubMatrix B%d from %d process\n", B_submatrix, 1);
					fflush(stdout);
					printf("I am 0 process. Send SubMatrix B%d to %d process\n",
						B_submatrix, 2);
					fflush(stdout);
				}
				// пересилання смуги матриці 4-му процесу
				MPI_Send(&B_submatrix, 1, MPI_INT, 4, 0, MPI_COMM_WORLD);
				MPI_Send(&B_columns, 1, MPI_INT, 4, 0, MPI_COMM_WORLD);
				for (j = 0; j < size2; j++)
					MPI_Send(b_temp[j], B_columns, MPI_DOUBLE, 4, 0, MPI_COMM_WORLD);
				// отримання частин матриці С після і-го кроку
				j = 0;
				for (int ii = 1; ii <= 8; ii++)
				{
					MPI_Recv(&A_rows, 1, MPI_INT, ii, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
					MPI_Recv(&B_columns, 1, MPI_INT, ii, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
					MPI_Recv(&B_submatrix, 1, MPI_INT, ii, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
					if (B_submatrix <= 3)
						shift = (B_submatrix - 1) * B_columns;
					else
						shift = ANOTHER_COLUMN_SIZE_INDEX + (B_submatrix - 4) * B_columns;
					for (k = 0; k < A_rows; k++, j++)
						MPI_Recv((C[j] + shift), B_columns, MPI_DOUBLE, ii, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
					if (out == 1)
					{
						printf("I am 0 process. Received SubMatrix C%d%d from %d process\n", ii, B_submatrix, ii);
						fflush(stdout);
					}
				}
			}

			QueryPerformanceCounter(&end);
			double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
			printf("\nElapsed Time: %f milliseconds\n\n", elapsedTime);
			PrintMatrixToFile(file, (char*)"Matrix C = ", C, size1, size3);
			DeleteMatrix(A, size1, size2);
			DeleteMatrix(B, size2, size3);
			DeleteMatrix(C, size1, size3);
			DeleteMatrix(b_temp, size2, MAX_COLUMN_SIZE);
			fclose(file);
		}
		else
		{
			sprintf(fileName, "Results_%d.txt", rank);
			FILE* file = fopen(fileName, "w");
			if (file == NULL)
			{
				printf("Error opening file. Check the path and permissions !\n");
				return 1;
			}
			MPI_Recv(&out, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			// отримання поточним процесом смуги матриці А
			int A_rows;
			MPI_Recv(&A_rows, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			double** a = CreateMatrix(A_rows, size2);
			for (i = 0; i < A_rows; i++)
				MPI_Recv(a[i], size2, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			if (out == 1)
			{
				printf("I am %d process. Received SubMatrix A%d in size %d x 112 from %d process\n", rank, rank, A_rows, 0);
				fflush(stdout);
				sprintf(SubMatrix, "SubMatrix A%d = ", rank);
				PrintMatrixToFile(file, SubMatrix, a, A_rows, size2);
			}
			// отримання поточним процесом смуги матриці B
			double** b = CreateMatrix(size2, MAX_COLUMN_SIZE);
			int B_columns, B_submatrix;
			MPI_Recv(&B_submatrix, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			MPI_Recv(&B_columns, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			for (i = 0; i < size2; i++)
				MPI_Recv(b[i], B_columns, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			if (out == 1)
			{
				printf("I am %d process. Received SubMatrix B%d in size 112 x %d from %d process\n", rank, B_submatrix, B_columns, 0);
				fflush(stdout);
				sprintf(SubMatrix, "SubMatrix B%d = ", B_submatrix);
				PrintMatrixToFile(file, SubMatrix, b, size2, B_columns);
			}
			double** c = CreateMatrix(A_rows, MAX_COLUMN_SIZE);
			// множення смуги матриці А на смугу матриці В
			MultMatrix(c, a, b, A_rows, size2, B_columns);
			if (out == 1)
			{
				printf("I am %d process. Multiplied SubMatrix A%d by B%d = SubMatrix C %d %d \n", rank, rank, B_submatrix, rank, B_submatrix);
				fflush(stdout);
				sprintf(SubMatrix, "SubMatrix C%d%d = A%d x B%d ", rank, B_submatrix, rank, B_submatrix);
				PrintMatrixToFile(file, SubMatrix, c, A_rows, B_columns);
				printf("I am %d process. Send SubMatrix C%d%d to %d process\n", rank, rank, B_submatrix, 0);
				fflush(stdout);
			}
			// надсилання частини матриці С після першого кроку
			MPI_Send(&A_rows, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
			MPI_Send(&B_columns, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
			for (i = 0; i < A_rows; i++)
				MPI_Ssend(c[i], B_columns, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
			int from, to;
			switch (rank)
			{
			case 1: from = 6; to = 8; break;
			case 2: from = 7; to = 5; break;
			case 3: from = 5; to = 6; break;
			case 4: from = 0; to = 7; break;
			case 5: from = 2; to = 3; break;
			case 6: from = 3; to = 1; break;
			case 7: from = 4; to = 2; break;
			case 8: from = 1; to = 0; break;
			}
			for (i = 2; i <= 8; i++)
			{
				// пересилання смуги матриці В від поточного процесу до процесу з рангом to
				if (out == 1)
				{
					printf("I am %d process. Send SubMatrix B%d to %d process\n",
						rank, B_submatrix, to);
					fflush(stdout);
				}
				MPI_Send(&B_submatrix, 1, MPI_INT, to, 0, MPI_COMM_WORLD);
				MPI_Send(&B_columns, 1, MPI_INT, to, 0, MPI_COMM_WORLD);
				for (j = 0; j < size2; j++)
					MPI_Send(b[j], B_columns, MPI_DOUBLE, to, 0, MPI_COMM_WORLD);
				// отримання смуги матриці В від процесу з рангом from поточним процесом
				MPI_Recv(&B_submatrix, 1, MPI_INT, from, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&B_columns, 1, MPI_INT, from, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				for (j = 0; j < size2; j++)
					MPI_Recv(b[j], B_columns, MPI_DOUBLE, from, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				if (out == 1)
				{
					printf("I am %d process. Received SubMatrix B%d from %d process\n", rank, B_submatrix, from);
					fflush(stdout);
					sprintf(SubMatrix, "SubMatrix B%d = ", B_submatrix);
					PrintMatrixToFile(file, SubMatrix, b, size2, B_columns);
				}
				// множення смуги матриці А на смугу матриці В
				MultMatrix(c, a, b, A_rows, size2, B_columns);
				if (out == 1)
				{
					printf("I am %d process. Multiplied SubMatrix A%d by B%d = SubMatrix C %d %d \n", rank, rank, B_submatrix, rank, B_submatrix);
					fflush(stdout);
					sprintf(SubMatrix, "SubMatrix C%d%d = A%d x B%d ", rank,
						B_submatrix, rank, B_submatrix);
					PrintMatrixToFile(file, SubMatrix, c, A_rows, B_columns);
				}
				// надсилання частини матриці С після і-го кроку
				MPI_Send(&A_rows, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
				MPI_Send(&B_columns, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
				MPI_Send(&B_submatrix, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
				for (j = 0; j < A_rows; j++)
					MPI_Send(c[j], B_columns, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
				if (out == 1)
				{
					printf("I am %d process. Sent SubMatrix C%d%d to %d process\n", rank, rank, B_submatrix, 0);
					fflush(stdout);
				}
			}
			DeleteMatrix(a, A_rows, size2);
			DeleteMatrix(b, size2, MAX_COLUMN_SIZE);
			DeleteMatrix(c, A_rows, MAX_COLUMN_SIZE);
			fclose(file);
		}
		MPI_Finalize();
		return 0;
	}