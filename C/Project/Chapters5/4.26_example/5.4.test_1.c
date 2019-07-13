#include <stdio.h>

int main()
{
    int i,sum=0;
    printf("«Î ‰»Î i,i=?");
    scanf("%d", &i);
    for (; i<=10; i++)
    {
        sum = sum + i;
    }
    printf("sum=%d\n", sum);
    return 0;
}