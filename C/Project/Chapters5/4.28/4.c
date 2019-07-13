#include <stdio.h>

int main()
{
    int a = 1, b = 1, c = 1;
    printf("%d,%d,%d\n",a,b,c);
    a += b += ++c;
    printf("%d,%d,%d\n",a,b,c);
    a = a > b, b = (a < b || b > c), c++;
    printf("%d,%d,%d\n",a,b,c);
}