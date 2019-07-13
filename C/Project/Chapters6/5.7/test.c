#include <stdio.h>
#include <string.h>
#define SIZE 16

int main()
{
    int a1[SIZE];
    int number1(int *a2[]);
    int i;
    scanf("%d", a1);
    //?????????
    for (i = 0; i <16; i++)
            printf("%5d", a1[i]);
    return 0;
}

int number1(int *a2[])
{
    int a[SIZE];
    int i;

    for (i = 0; i <16; i++)
        a[i] = a[i] + 6;

}