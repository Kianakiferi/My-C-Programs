#include <stdio.h>
#include <string.h>
#define SIZE 10

int main()
{
    char c[SIZE];
    char t;
    int i, j, x;

    printf("Plz Enter Something...\n");
    gets(c);
    x = strlen(c);
    for (j = 0; j < x - 1; j++)
    {
        for (i = 0; i < x - 1 - j; i++)
        {
            if (c[i] > c[i + 1])
            {
                t = c[i];
                c[i] = c[i + 1];
                c[i + 1] = t;
            }
        }
    }
    puts(c);
    return 0;
}