#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    int n = 1048576;
    double *A, *B, *C;
    A = (double*)malloc(n * sizeof(double));
    B = (double*)malloc(n * sizeof(double));
    C = (double*)malloc(n * sizeof(double));

    srand(time(NULL));

    for (int i = 0; i < n; i++){
        B[i] = (double)rand() / (double)RAND_MAX;
        C[i] = (double)rand() / (double)RAND_MAX;
        A[i] = B[i] + C[i];
    }
    printf("A[0] = %f\n", A[0]);
    printf("A[n-1] = %f\n", A[n-1]);

    free(A);
    free(B);
    free(C);
}