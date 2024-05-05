#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
#pragma ide diagnostic ignored "cert-err34-c"
#pragma ide diagnostic ignored "cert-msc51-cpp"
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int n_optimized = 0;
int n_unoptimized = 0;

int** CreateMatrix(int n) {
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    return a;
}

int*** CreateMatrix3D(int n)
{
    int*** a = new int** [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int* [n];
        for (int j = 0; j < n; j++)
        {
            a[i][j] = new int[n + 1];
        }
    }
    return a;
}

void DeleteMatrix(int** a, int n) {
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}

void DeleteMatrix3D(int*** a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            delete[] a[i][j];
        }
        delete[] a[i];
    }
    delete[] a;
}

void FillMatrix(int** a, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = rand() % 10;
}

void InputMatrix(int** a, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter [%d][%d] element = ", i, j);
            scanf("%d", &(a[i][j]));
        }
        printf("\n");
    }
}

void PrintMatrix(int** a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

int** Martix3Dto2D(int** a, int*** b, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            a[i][j] = b[i][j][n];
    }
    return a;
}

void PrintMatrix3D(int*** a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d\t", a[i][j][n]);
        printf("\n");
    }
    printf("\n");
}

void PrintMatrixToFile(FILE* f, char* title, int** a, int n)
{
    fprintf(f, "%s", title);
    fprintf(f, "\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            fprintf(f, "%d\t", a[i][j]);
        fprintf(f, "\n");
    }
    fprintf(f, "\n");
}

int** MultMatrix(int** c, int** a, int** b, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
        }
    return c;
}

int** MultMatrixOneTime(int** c, int** a, int** b, int n)
{
    int*** c3D = CreateMatrix3D(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            c3D[i][j][0] = 0;
            for (int k = 0; k < n; k++)
                c3D[i][j][k + 1] = c3D[i][j][k] + a[i][k] * b[k][j];
        }
    Martix3Dto2D(c, c3D, n);
    DeleteMatrix3D(c3D, n);

    return c;
}

int** MultMatrixLocalAlgorithm(int** c, int** a, int** b, int n)
{
    int*** c3D = CreateMatrix3D(n);
    int*** a3D = CreateMatrix3D(n);
    int*** b3D = CreateMatrix3D(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            c3D[i][j][0] = 0;
            a3D[i][j][0] = a[i][j];
            b3D[i][j][0] = b[i][j];
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                n_unoptimized += 2;
                c3D[i][j][k + 1] = c3D[i][j][k] + a3D[i][k][j] * b3D[k][j][i];
                a3D[i][k][j + 1] = a3D[i][k][j];
                b3D[k][j][i + 1] = b3D[k][j][i];
            }
        }
    Martix3Dto2D(c, c3D, n);
    DeleteMatrix3D(c3D, n);
    DeleteMatrix3D(a3D, n);
    DeleteMatrix3D(b3D, n);
    return c;
}

void MultMatrixRecursAalgorithm(int*** c3D, int*** a3D, int*** b3D, int n)
{
    static int i = 0, j = 0, k = 0;
    if (i < n)
    {
        if (j < n)
        {
            if (k < n)
            {
                if (!a3D[i][k][j] || !b3D[k][j][i]) {}
                else if (a3D[i][k][j] == 1 || b3D[k][j][i] == 1) n_optimized++;
                else n_optimized += 2;

                c3D[i][j][k + 1] = c3D[i][j][k] + a3D[i][k][j] * b3D[k][j][i];
                a3D[i][k][j + 1] = a3D[i][k][j];
                b3D[k][j][i + 1] = b3D[k][j][i];
                k++;
                MultMatrixRecursAalgorithm(c3D, a3D, b3D, n);
            }
            k = 0;
            j++;
            MultMatrixRecursAalgorithm(c3D, a3D, b3D, n);

        }
        j = 0;
        i++;
        MultMatrixRecursAalgorithm(c3D, a3D, b3D, n);
    }
}

int** MultMatrixRA(int** c, int** a, int** b, int n)
{
    int*** c3D = CreateMatrix3D(n);
    int*** a3D = CreateMatrix3D(n);
    int*** b3D = CreateMatrix3D(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            c3D[i][j][0] = 0;
            a3D[i][j][0] = a[i][j];
            b3D[i][j][0] = b[i][j];
        }
    MultMatrixRecursAalgorithm(c3D, a3D, b3D, n);
    Martix3Dto2D(c, c3D, n);
    DeleteMatrix3D(c3D, n);
    DeleteMatrix3D(a3D, n);
    DeleteMatrix3D(b3D, n);
    return c;
}

int **GenA(int n)
{
    int** a = CreateMatrix(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = j + i + 1 > n ? 0 : j + i + 1;

    return a;
}

int **GenB(int n)
{
    int** b = CreateMatrix(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i][j] = j > n / 2 ? (-100 + rand() % 200) : 0;

    return b;
}

int main()
{
    srand((unsigned int)time(nullptr));
    int n;
    printf("Enter the matrix size n : ");
    scanf("%d", &n);
    int** A = GenA(n);
    int** B = GenB(n);

    const char* fileName = "Results.txt";
    FILE* file = fopen(fileName, "w");
    if (file == nullptr)
    {
        printf("\nError opening file. Check the path and permissions !\n");
        return 1;
    }

    PrintMatrixToFile(file, (char*)"Matrix B = ", A, n);
    printf("Matrix A :\n");
    PrintMatrix(A, n);

    PrintMatrixToFile(file, (char*)"Matrix B = ", B, n);
    printf("Matrix B :\n");
    PrintMatrix(B, n);

    int** C = CreateMatrix(n);
    MultMatrix(C, A, B, n);
    printf("Matrix C = A * B :\n");
    PrintMatrixToFile(file, (char*)"Matrix C = A * B = ", C, n);
    PrintMatrix(C, n);
    MultMatrixOneTime(C, A, B, n);
    printf("Matrix C = A * B, program with one-time assignment :\n");
    PrintMatrixToFile(file, (char*)"Matrix C = A * B = ", C, n);
    PrintMatrix(C, n);
    MultMatrixLocalAlgorithm(C, A, B, n);
    printf("Matrix C = A * B, program with the localized algorithm:\n");
    PrintMatrixToFile(file, (char*)"Matrix C = A * B = ", C, n);
    PrintMatrix(C, n);

    MultMatrixRA(C, A, B, n);
    printf("Matrix C = A * B, program with the recursive localized algorithm :\n");
    PrintMatrixToFile(file, (char*)"Matrix C = A * B = ", C, n);
    PrintMatrix(C, n);
    DeleteMatrix(A, n);
    DeleteMatrix(B, n);
    DeleteMatrix(C, n);
    fclose(file);

    printf("n optimized %d\nn unoptimized: %d", n_optimized, n_unoptimized);
    return 0;
}
#pragma clang diagnostic pop