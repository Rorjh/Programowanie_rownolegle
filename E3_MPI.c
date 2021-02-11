#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int n = 1024;
    int A[n];
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    //proces 0 odczytuje dane z pliku i wspisuje do tablicy
    if (rank == 0)
    {
        FILE *f = fopen("data.txt", "r");

        for (int i = 0; i < n; i++)
        {
            fscanf(f, "%d", &A[i]);
        }
    }

    int chunk = n / size;
    int A_part[chunk];
    
    //rozesłanie danych z procesu 0 do reszty
    MPI_Scatter(A, chunk, MPI_INT, A_part, chunk, MPI_INT, 0, MPI_COMM_WORLD);

    //inicjalizacja tablicy z histogramem
    int B[101];
    //zapełnienie tej tablicy zerami
    for (int i = 0; i < 101; i++)
    {
        B[i] = 0;
    }
    //zliczanie liczby wystąpień każdej z wartości - każdy proces przetwarza część tablicy z danymi
    for (int i = 0; i < chunk; i++)
    {
        B[A_part[i]] += 1;
    }

    //zebranie wyników na procesorze 0
    int B_reduced[101];
    MPI_Reduce(&B, &B_reduced, 101, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    //procesor 0 wypisuje wyniki
    if (rank == 0)
    {
        for (int i = 0; i < 101; i++)
        {
            printf("B[%d] = %d\n", i, B_reduced[i]);
        }
    }

    MPI_Finalize();
    return 0;
}