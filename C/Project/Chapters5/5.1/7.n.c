#include <stdio.h>

int main()
{
    int i, n;
    double sum = 1.0;

    printf("int n=");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        sum = sum * i;
    printf("%d!=%lf\n", n, sum);
    
    printf("sum= %lf", sum);
    return 0;
}