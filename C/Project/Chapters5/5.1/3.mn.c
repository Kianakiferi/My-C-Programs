#include <stdio.h>

int main()
{
    int Max_Common_Divisor(int a, int b);
    int Min_Common_Divisor(int x, int y, int z);
    int n1, n2, m1, m2;

    printf("请输入数字：");
    scanf("%d %d", &n1, &n2);
    m1 = Max_Common_Divisor(n1, n2);
    m2 = Min_Common_Divisor(n1, n2, m1);
    printf("最大公约数为：%d\n最小公约数为：%d", m1, m2);
    return 0;
}

int Max_Common_Divisor(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

int Min_Common_Divisor(int x, int y, int z)
{
    int m;
    m = x * y / z;
    return m;
}