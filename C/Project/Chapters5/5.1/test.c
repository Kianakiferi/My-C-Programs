#include <stdio.h>
#include <string.h>
#define SIZE 512

int main()
{
    char c[SIZE], *p;
    int i, x = 0;

    printf("«Î ‰»Î:");
    gets(c);

    p = c;
    while (*p != '\0')
    {
        x++;
        p++;
    }
    printf("x=%d",x);
    return 0;
}