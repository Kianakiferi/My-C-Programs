#include <stdio.h>

int main()
{
    int x = 1,y = 1, i;
    
    for (i = 1; i < 100; i++)
    {
        y = y + 1;
        x = x + y;
    }
    printf("Sum = %d",x);
    return 0;
}