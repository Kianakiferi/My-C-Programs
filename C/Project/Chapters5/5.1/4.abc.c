#include <stdio.h>

int main()
{
    int a = 0, s = 0, n = 0, e = 0;
    char x;

    printf("������:\n");
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
    printf("�����ַ��У�%d����ĸ��%d���ո�%d�����֣�%d�������ַ���", a, s, n, e);
    return 0;
}