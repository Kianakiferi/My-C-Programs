#include <stdio.h>
#include <string.h>
#define SIZE 512

int main()
{
    char c[SIZE];
    int i, x;

    printf("Plz input something: ");
    scanf("%s", c);
    x = strlen(c);
    for (i = 0; i < x; i++)
    {
        if ((c[i] >= 'A') && (c[i] <= 'Z'))
            c[i] = 'A' + ('Z' - c[i]);
        else if ((c[i] >= 'a') && (c[i] <= 'z'))
            c[i] = 'a' + ('z' - c[i]);
    }
    printf("Enciphered data is: %s\n", c);

    for (i = 0; i < x; i++)
    {
        if ((c[i] >= 'A') && (c[i] <= 'Z'))
            c[i] = 'A' + ('Z' - c[i]);
        else if ((c[i] >= 'a') && (c[i] <= 'z'))
            c[i] = 'a' + ('z' - c[i]);
    }
    printf("Original data is: %s\n", c);
    return 0;
}