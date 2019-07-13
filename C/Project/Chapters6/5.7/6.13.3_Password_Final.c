#include <stdio.h>
#include <string.h>
#define SIZE 512

int main()
{
    void AZ(char a[], int x);
    char c[SIZE];
    int x;

    printf("Plz input something: ");
    gets(c);
    x = strlen(c);
    AZ(c, x);
    printf("Enciphered data is:  %s\n", c);
    AZ(c, x);
    printf("Original data is:    %s\n", c);
    return 0;
}

void AZ(char a[], int x)
{
    int i;
    for (i = 0; i < x; i++)
    {
        if ((a[i] >= 'A') && (a[i] <= 'Z'))
            a[i] = 'A' + ('Z' - a[i]);
        else if ((a[i] >= 'a') && (a[i] <= 'z'))
            a[i] = 'a' + ('z' - a[i]);
    }
}