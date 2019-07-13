#include <stdio.h>
int main()
{
    int a;
    float b;
    scanf("%f", &b);
    a = b / 10;
    printf("%d\n", a);
    switch (a)
    {
        case 0:
            printf("A\n");
            break;
        case 1:
            printf("B\n");
            break;
        case 2:
            printf("C\n");
            break;
        default:
            printf("??????\n");
            break;
    }
    return 0;
}