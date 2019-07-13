#include <stdio.h>
#include <string.h>
#define SIZE 3

int main()
{
    char c1[16], c2[16];

    gets(c1);
    gets(c2);

    if (strcmp(c1,c2)>0)
    {
        printf("c1>c2");
    }
    
}