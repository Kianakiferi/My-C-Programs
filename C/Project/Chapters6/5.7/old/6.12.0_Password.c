#include <stdio.h>

int main()
{
    char c;

    printf("Plz input something: ");
    c = getchar();
    while (c != '\n')
    {
        if ((c >= 'A') && (c <= 'Z'))
            c = 65 + (90 - c);
        else if ((c >= 'a') && (c <= 'z'))
            c = 97 + (122 - c);
        printf("%c", c);
        c = getchar();
    }
    printf("\n");
    return 0;
}