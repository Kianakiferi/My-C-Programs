#include <stdio.h>
#include <string.h>
#define SIZE 512

int main()
{
    void AZ(char *p);
    char c[SIZE];
    int i, x, *p;

    printf("Plz input something: ");
    gets(c);
    x = strlen(c);
    for (i = 0; i < x; i++)
    {
        p = &c[i];
        AZ(p);
    }
    printf("Enciphered data is: %s\n", c);

    for (i = 0; i < x; i++)
    {
        p = &c[i];
        AZ(p);
    }
    printf("Original data is: %s\n", c);
    return 0;
}

void AZ(char *p)
{
    if ((*p >= 'A') && (*p <= 'Z'))
        *p = 'A' + ('Z' - *p);
    else if ((*p >= 'a') && (*p <= 'z'))
        *p = 'a' + ('z' - *p);
}