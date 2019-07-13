#include <stdio.h>
#include <string.h>
#define SIZE 512

int main()
{
    char c[SIZE], *p;
    int a = 0, s = 0, n = 0, e = 0;

    printf("请输入:\n");
    gets(c);
    p = c;
    while (*p != '\0')
    {
        if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z'))
            a++;
        else if (*p == ' ')
            s++;
        else if ((*p >= '0') && (*p <= '9'))
            n++;
        else
            e++;
        p++;
    }
    printf("这行字符有：%d个字母，%d个空格，%d个数字，%d个其他字符。", a, s, n, e);
    return 0;
}