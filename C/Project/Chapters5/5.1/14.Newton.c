#include <stdio.h>
#include <math.h>

int main()
{
    double x1, x2, y1, y2,i;

    printf("请扣初始值x1：");
    scanf("%lf", &x1);

    for (i = 10; i >1e-5; i=x2-x1)
    {
        x1 = x2;
        y1=((2*x1-4)*x1+3)*x1-6;
        y2 = (6 * x1 - 8) * x1 + 3;
        x2 = x1 - (y1 / y2);
    }
    printf("根为：%lf", x2);
    return 0;
}