#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void)
{

    int n = 1024;

    srand(time(NULL));

    double A[n];

    for (int i = 0; i < n; i++)
    {
        A[i] = (double)rand() / (double)RAND_MAX;
    }

    double sum = 0;

    for (int i = 0; i < n; i++){
        sum += A[i] * A[i];
    }

    double norm = sqrt(sum);
    
    printf("Norm = %f\n", norm);

    return 0;
}