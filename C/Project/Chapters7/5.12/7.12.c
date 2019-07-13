#include <stdio.h>
#define SIZE 10

int main()
{
    void sort(int array[], int n);
    int a[SIZE], i;

    for (i = 0; i < SIZE; i++)
    {
        printf("Enter array %d: ",i+1);
        scanf("%d", &a[i]);
    }
    sort(a, SIZE);
    printf("The sorted array: \n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

void sort(int array[], int n)
{
    int i, j, k, t;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (array[i] < array[k])
                k = j;
        }
        t = array[k];
        array[k] = array[i];
        array[i] = t;
    }
}