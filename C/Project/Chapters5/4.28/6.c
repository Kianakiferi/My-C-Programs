#include <stdio.h>

int main()
{
    int x1, x2, max1, max2, min1, min2, i;
    int max(int x1, int y1);
    int min(int x2, int y2);
    
    for (i = 1; i <= 5; i++)
    {
        printf("Plz input data: ");
        scanf("%d", &x1);
        printf("Plz input data: ");
        scanf("%d", &x2);

        max1 = max(x1, x2);
        {
            if (i > 1)
                max2 = max(max1, max2);
            else
                max2 = max1;
        }

        min1 = min(x1, x2);
        {
            if (i > 1)
                min2 = min(min1, min2);
            else
                min2 = min1;
        }
        
    }
    printf("Max= %d, Min= %d\n", max2, min2);
    return 0;
}
    int max(int x1, int y1)
    {
        int m;
        if(x1>y1)
            m = x1;
        else
            m = y1;
        return (m);
    }

    int min(int x2, int y2)
    {
        int m;
        if(x2>y2)
            m = y2;
        else
            m = x2;
        return (m);
    }