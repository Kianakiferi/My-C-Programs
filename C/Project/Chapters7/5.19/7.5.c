#include <stdio.h>
#include <string.h>
#define SIZE 512

int main()
{
    char c[SIZE], s[SIZE];
    int i, x, y;

    printf("Plz Enter Something...\n");
    gets(c);
    x = strlen(c);
    strcpy(s, c);
    for (i = 0; i < x; i++)
    {
        c[i] = s[x - 1 - i];
    }
    printf("Bibbidi Bobbidi Boo~\n");
    puts(c);
    return 0;
}