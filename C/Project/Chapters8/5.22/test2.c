#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char c[10] = {' ', ' ', ' ', ' ', ' ', ' ', '1', '2', '3', ' '};
    int a[5] = {1, 2, 3, 4, 5};
    int i;

    a[0] = atoi(c);
    a[1] = strlen(c);
    a[2] = sizeof(int);

    for (i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}