#include <stdio.h>
#define SIZE 3

int main()
{
    int Sum(int s[SIZE][SIZE]);
    int a[SIZE][SIZE];
    int x, y, sum;

    for (x = 0; x < SIZE; x++)
    {
        for (y = 0; y < SIZE; y++)
        {
            printf("Plz input row %d number %d: ", x + 1, y + 1);
            scanf("%d", &a[x][y]);
        }
    }
    sum = Sum(a);
    printf("Sum = %d", sum);
    return 0;
}

int Sum(int s[SIZE][SIZE])
{
    int i, sum = 0;

    for (i = 0; i < SIZE; i++)
    {
        sum = sum + s[i][i] + s[i][SIZE - 1 - i];
    }
    if(SIZE%2==1)
        sum = sum - s[(SIZE - 1) / 2][(SIZE - 1) / 2];
    return sum;
}