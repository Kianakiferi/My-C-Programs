#include <stdio.h>

int main()
{
    char a, b;

    printf("Plz input A: ");
    scanf(" %c", &a);
    printf("Plz input B: ");
    scanf(" %c", &b);

    if (a > b)
        printf("a>b");
    else if (a < b)
        printf("a<b");
    else
        printf("a=b");
    return 0;
}