#include <stdio.h>

int main()
{
    int i, n;
    double sum1 = 1.0, sum2 = 0.0;

    for (n = 1; n <= 20; n++)
    {
        for (i = 1; i <= n; i++)
            sum1 = sum1 * i;
        sum2 = sum1 + sum2;
        sum1 = 1.0;
    }
    printf("½á¹ûÎª£º%lf", sum2);
    return 0;
}