#include <stdio.h>
#define SIZE 4

int main()
{
    int a[SIZE][SIZE] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int i,j, *p;

    p = *a;
    for (i = 0; i < SIZE; i++)
    {
        for ( j = 0; j < SIZE; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
 