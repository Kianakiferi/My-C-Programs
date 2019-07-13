#include <stdio.h>
#define SIZE 10

int main()
{
    int a[SIZE] = {-6, -6, 0, 1, 5, 16, 66, 99, 100, 0};
    int x, i, j, t;

    printf("Plz input one number: ");
    scanf("%d", &a[SIZE - 1]);
    if (a[SIZE - 1] > a[SIZE - 2])
    {
    }
    else
    {
        for (j = 0; j < 9; j++)
        {
            for (i = 0; i < 9 - j; i++)
            {
                if (a[i] > a[i + 1])
                {
                    t = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = t;
                }
            }
        }
    }
    printf("List is: ");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}