#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    FILE *f = fopen("data.txt", "w");

    if (f == NULL)
    {
        printf("Blad otwarcia pliku\n");
        exit(-1);
    }
    int n = 1024;
    srand(time(NULL));
    int number;
    for (int i = 0; i < n; i++)
    {
        number = rand() % 101;
        if (i != n - 1)
        {

            fprintf(f, "%d\n", number);
        }
        else
        {
            fprintf(f, "%d", number);
        }
    }
    fclose(f);

    return 0;
}
