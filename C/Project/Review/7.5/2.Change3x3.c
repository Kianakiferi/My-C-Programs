#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 3

int main()
{
    void PrintA(int x[SIZE][SIZE]);
    void Change(int y[SIZE][SIZE]);
    int a[SIZE][SIZE];
    int i, j;
    
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("Plz input Line %d, Number %d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Array 1 is: \n");
    PrintA(a);

    Change(a);
    
    printf("Array 2 is: \n");
    PrintA(a);
    return 0;
}

void PrintA(int x[SIZE][SIZE])
{
    int i, j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("%d ", x[i][j]);
            if (j + 1 == SIZE)
                printf("\n");
        }
    }
}

void Change(int b[SIZE][SIZE])
{
    int save[SIZE][SIZE]={0};
    int i, j;

    memcpy(save, b,SIZE*SIZE*sizeof(int));

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            b[i][j] = save[j][i];
        }
    }
}