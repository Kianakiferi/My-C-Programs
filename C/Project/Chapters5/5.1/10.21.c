#include <stdio.h>

int main()
{
    int i;
    double x=1, y=2, sum=0, z;

    for (i=1; i <=20; i++)
    {
        sum = sum + y / x;
        z = y;
        y = x + y;
        x = z;
    }
    printf("ºÍÎª£º%lf", sum);
    return 0;
}