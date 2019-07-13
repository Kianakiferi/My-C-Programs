#include <stdio.h>

int main()
{
    int x = 3;
    switch (x)
    {
        case 1:
        case 2:
            printf("x<3\n");
        case 3:
            printf("x=3\n");
        case 4:
        case 5:
            printf("x>3\n");
        default:
            printf("x ??????\n");
    }

}