#include <stdio.h>

int main()
{
    int i,sum=0;
    printf("������ i,i=?");
    scanf("%d", &i);
    do
    {
        sum = sum + i;
        i++;
    } while (i<=10);
    printf("sum=%d\n", sum);
    return 0;
}