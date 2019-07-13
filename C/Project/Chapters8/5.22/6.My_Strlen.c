#include <stdio.h>
#define SIZE 512

int main()
{
    int My_Strlen(char c[]);
    char a[SIZE];
    int len;

    printf("Plz enter something: ");
    gets(a);

    len = My_Strlen(a);
    printf("This Sentens Have %d Character", len);
    return 0;
}

int My_Strlen(char c[])
{
    char *p;
    int num = 0;

    p = c;
    while (*p != '\0')
    {
        num++;
        p++;
    }
    return num;
}