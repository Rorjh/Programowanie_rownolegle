#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int n = 1024;
    int A[n];

    FILE *f = fopen("data.txt", "r");

    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%d", &A[i]);
    }

    int B[101];
    int sum;

    for (int i = 0; i < 101; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        if (A[j] == i)
        {
            sum += 1;
        }

        B[i] = sum;
        printf("B[%d] = %d\n", i, B[i]);
    }

    return 0;
}