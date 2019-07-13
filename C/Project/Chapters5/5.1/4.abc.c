#include <stdio.h>

int main()
{
    int a = 0, s = 0, n = 0, e = 0;
    char x;

    printf("请输入:\n");
    while ((x = getchar()) != '\n')
    {
        if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
            a++;
        else if (x == ' ')
            s++;
        else if ((x >= '0') && (x <= '9'))
            n++;
        else
            e++;
    }
    printf("这行字符有：%d个字母，%d个空格，%d个数字，%d个其他字符。", a, s, n, e);
    return 0;
}