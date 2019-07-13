#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, disc, x1, x2, realpart, imagpart;
    
    scanf("%lf,%lf,%lf", &a, &b, &c);
    printf("该方程");
    if(fabs(a)<=1e-6)
        printf("无根\n");
    else
    {
        disc = b * b - 4 * a * c;
        if(fabs(disc)<=1e-6)
            printf("有两个相等根：%8.4f\n", -b / (2 * a));
        else
            if(disc>1e-6)
            {
                x1 = (-b + sqrt(disc)) / (2.0 * a);
                x2 = (-b - sqrt(disc)) / (2.0 * a);
                printf("有两个实根：%8.4f and %8.4f\n", x1, x2);
            }
            else
            {
                realpart = -b / (2.0 * a);
                imagpart = sqrt(-disc) / (2.0 * a);
                printf("有两个共轭复根：\n");
                printf("%8.4f+%8.4fi\n",realpart,imagpart);
                printf("%8.4f-%8.4fi\n",realpart,imagpart);
            }
    }
    return 0;
}