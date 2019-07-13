#include <stdio.h>

int main()
{
    int g1,g2;
    char gf;
    
    printf("请输入分数: ");
    scanf("%d", &g1);
    g2 = g1 / 10;
    switch (g2)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            gf = 'E';
            break;
        case 6:
            gf = 'D';
            break;
        case 7:
            gf = 'C';
            break;
        case 8:
            gf = 'B';
            break;
        case 9:
        case 10:
            gf = 'A';
            break;
        default:
            gf = '?';
            printf("??????????\n");
            return 0;
            break;
    }
    printf("你的成绩为：%c\n", gf);
    return 0;
}