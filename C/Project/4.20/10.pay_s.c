#include <stdio.h>
int main()
{
    float i, m, m1, m2, m3, m4, m5;
    m1 = 100000 * 0.1;
    m2 = m1 + 100000 * 0.075;
    m3 = m2 + 200000 * 0.05;
    m4 = m3 + 200000 * 0.03;
    m5 = m4 + 400000 * 0.015;
    int p;

    printf("请输入利润I：");
    scanf("%f", &i);
    p = i / 100001; //要 <=
    if (p > 10)
        m = m5 + (i - 1000000) * 0.01;
    else
    {
        switch (p)
        {
        case 0: //100000元以下
            m = i * 0.1;
            break;
        case 1:
            m = m1 + (i - 100000) * 0.075;
            break;
        case 2:
        case 3: //400000元以下
            m = m2 + (i - 200000) * 0.05;
            break;
        case 4:
        case 5: //600000元以下
            m = m3 + (i - 400000) * 0.03;
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            m = m4 + (i - 600000) * 0.015; //1000000元以下
            break;
        default:
            m = 0;
            printf("??????????");
            return 0; //有问题时就扣个?
            break;
        }
    }
    printf("奖金为： %10.2f", m);
    return 0;
}