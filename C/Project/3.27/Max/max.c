#include <stdio.h>
int main()
{
    int max(int x, int y, int z);
    int a, b, c, d;
    printf("Plz type 3 numbers like: 1 2 3\n");
    scanf("%d %d %d", &a, &b, &c);
    d = max(a, b, c);
    printf("max is %d\n", d);
    return 0;
}

    int max(int x,int y,int z)
    {
        int m;
        if(x>y)
            m=x;
        else
            m=y;
        if(z>m)
            m=z;
        return(m);
    }