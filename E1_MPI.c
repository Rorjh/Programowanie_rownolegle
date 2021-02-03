#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int n = 1048576;
    //Alokacja pamięci
    double *A, *B, *C;
    A = (double *)malloc(n * sizeof(double));
    B = (double *)malloc(n * sizeof(double));
    C = (double *)malloc(n * sizeof(double));

    //Generator liczb losowych;
    srand(time(NULL));

    int rank, size;
    int chunk = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    //Liczba elementów tablicy przetwarzanych przez każdy z procesorów:
    chunk = n / size;

    //Procesor nr 0 wypełnia tablice liczbami losowymi
    if (rank == 0)
    {
        for (int i = 0; i < n; i++)
        {
            B[i] = (double)rand() / (double)RAND_MAX;
            C[i] = (double)rand() / (double)RAND_MAX;
            //printf("B %f C %f\n", B[i], C[i]);
        }
    }

    //Inicjalizacja mniejszych tablic dla części przetwarzanych przez różne procesory
    double *a_part, *b_part, *c_part;
    a_part = (double *)malloc(chunk * sizeof(double));
    b_part = (double *)malloc(chunk * sizeof(double));
    c_part = (double *)malloc(chunk * sizeof(double));

    //Rozsłanie danych z procesora nr 0 do reszty
    MPI_Scatter(B, chunk, MPI_DOUBLE, b_part, chunk, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Scatter(C, chunk, MPI_DOUBLE, c_part, chunk, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    //Obliczenie sumy
    for (int i = 0; i < chunk; i++)
    {
        a_part[i] = b_part[i] + c_part[i];
        //printf("A %f B %f C %f\n", A[i], B[i], C[i]);
    }

    //Zebranie danych ze wszystkich pocesorów w procesorze nr 0
    MPI_Gather(a_part, chunk, MPI_DOUBLE, A, chunk, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    //Zwolnienie pamieci
    free(a_part);
    free(b_part);
    free(c_part);
    //Proces 0 wyswietla wyniki
    if (rank == 0)
    {
        printf("A_[0] = %f, rank = %d\n", A[0], rank);
        printf("A[n-1] = %f, rank = %d\n", A[n - 1], rank);
    }

    MPI_Finalize();
    free(A);
    free(B);
    free(C);

    return 0;
}