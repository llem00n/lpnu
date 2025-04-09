#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <windows.h>

#define size1 3000
#define size2 1120
#define size3 2140

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
void FillMatrix(double** a, int m, int n, int mode)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (mode >= 0)
			{
				a[i][j] = mode;
			}
			else if (mode == -1)
			{
				a[i][j] = 1 + (rand() % 9);
			}
			else if (mode == -2)
			{
				a[i][j] = (10 + (rand() % 90)) * (rand() % 2 == 0 ? 1 : -1);
			}
			else
			{
				a[i][j] = (100 + (rand() % 9900)) + (rand() / (double)RAND_MAX);
			}
		}
}
void PrintMatrixToFile(FILE* f, char* title, double** a, int m, int n)
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
	LARGE_INTEGER frequency, start, end;
	double** A = CreateMatrix(size1, size2);
	double** B = CreateMatrix(size2, size3);
	double** C = CreateMatrix(size1, size3);
	FILE* file = fopen("Results.txt", "w");
	if (file == NULL)
	{
		printf("\nError opening file. Check the path and permissions !\n");
		return 1;
	}
	static int modes[2];
	printf("Available modes:\n");
	printf("0+      fill with 'mode' value\n");
	printf("-1      fill with random ints from 1 to 9\n");
	printf("-2      fill with random ints from (-)10 to (-)99\n");
	printf("-3      fill with random doubles from 100 to 9999\n");
	printf("Select A matrix mode:\n");
	fflush(stdout);
	scanf("%d", &modes[0]);
	printf("Select B matrix mode:\n");
	fflush(stdout);
	scanf("%d", &modes[1]);

	// random input matrix A
	FillMatrix(A, size1, size2, modes[0]);
	PrintMatrixToFile(file, (char*)"Matrix A = ", A, size1, size2);
	// random input matrix B
	FillMatrix(B, size2, size3, modes[1]);
	PrintMatrixToFile(file, (char*)"Matrix B = ", B, size2, size3);
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	MultMatrix(C, A, B, size1, size2, size3);
	QueryPerformanceCounter(&end);
	double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
	printf("\nElapsed Time: %f milliseconds\n\n", elapsedTime);
	PrintMatrixToFile(file, (char*)"Matrix C = ", C, size1, size3);
	DeleteMatrix(A, size1, size2);
	DeleteMatrix(B, size2, size3);
	DeleteMatrix(C, size1, size3);
	fclose(file);
	return 0;
}