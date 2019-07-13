#include <stdio.h>
int main()
{
    float r,h,c1,s1,s2,v1,v2;
    const float PI = 3.1415926;
    printf("请输入半径：");
    scanf("%f", &r);
    printf("请输入圆柱高:");
    scanf("%f", &h);
    c1 = 2 * PI * r;
    s1 = PI * r * r;
    s2 = 4 * PI * r * r;
    v1 = 4 / 3 * PI * r * r * r;
    v2 = PI * r * r * h;
    printf("圆周长为%7.2f\n圆面积为%7.2f\n球表面积为%7.2f\n球体体积为%7.2f\n圆柱高为%7.2f\n", c1, s1, s2, v1, v2);
    return 0;
}