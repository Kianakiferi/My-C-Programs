#include <stdio.h>
#include <string.h>
#define SIZE 512

int main()
{
    char c[SIZE], *p;
    int a = 0, s = 0, n = 0, e = 0;

    printf("������:\n");
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
    printf("�����ַ��У�%d����ĸ��%d���ո�%d�����֣�%d�������ַ���", a, s, n, e);
    return 0;
}