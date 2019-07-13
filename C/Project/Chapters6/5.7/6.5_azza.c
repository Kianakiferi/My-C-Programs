#include <stdio.h>
#define SIZE 10

int main()
{
    int a[SIZE];
    int x, i;

    for (x = 0; x < SIZE; x++)
    {
        printf("Plz input number %d: ", x + 1);
        scanf("%d", &a[x]);
    }

    printf("List is: ");
    for (i = SIZE - 1; i >= 0; i--)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}