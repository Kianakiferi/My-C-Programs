#include <stdio.h>
#define SIZE 4

int main()
{
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
    
}
