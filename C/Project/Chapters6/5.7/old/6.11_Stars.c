#include <stdio.h>

int main()
{
    char c[5] = {'*', '*', '*', '*', '*'};
    int i;

    for (i = 0; i < 5; i++)
        printf("%c ", c[i]);

    printf("\n  ");
    for (i = 0; i < 5; i++)
        printf("%c ", c[i]);

    printf("\n    ");
    for (i = 0; i < 5; i++)
        printf("%c ", c[i]);

    printf("\n      ");
    for (i = 0; i < 5; i++)
        printf("%c ", c[i]);

    printf("\n        ");
    for (i = 0; i < 5; i++)
        printf("%c ", c[i]);

    return 0;
}