#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <mpi.h>

int main(int argc, char **argv)
{

    int n = 1024;
    //generator liczb losowych
    srand(time(NULL));

    double A[n];

    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    //zapełnienie tablicy liczbami losowymi - każdy proces generuje taką samą tablicę
    for (int i = 0; i < n; i++)
    {
        A[i] = (double)rand() / (double)RAND_MAX;
    }

    double sum = 0;
    int chunk = n / size;
    //zliczanie sumy kwadratów elementów wektora - każdy procesor przetwarza część tablicy
    for (int i = chunk * rank; i < chunk * (rank + 1); i++)
    {
        sum += A[i] * A[i];
    }
    //printf("SUM = %f\n", sum);
    
    //Zsumowanie wyników na procesorze 0
    double receive;
    MPI_Reduce(&sum, &receive, size, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    //procesor 0 liczy pierwiastek i wypisuje ostateczny wynik
    if (rank == 0)
    {
        double norm = sqrt(receive);
        printf("Norm = %f\n", norm);
    }

    MPI_Finalize();

    return 0;
}