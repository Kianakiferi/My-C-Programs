#include <stdio.h>
#include <string.h>
#define SIZE 512

int main()
{
    void Change(char c[]);
    char a[SIZE];

    printf("Plz enter something: ");
    gets(a);

    Change(a);
    
    printf("THe Changed Sentence is: %s ", a);
    return 0;
}

void Change(char c[])
{
    int len = strlen(c);
    char s[len], *p;
    int i;

    strcpy(s, c);
    p = c;
    for (i = len - 1; i >= 0; i--)
    {
        *p = s[i];
        p++;
    }
}