#include <stdio.h>
int main()
{
    int Pnx(int n, int x);
    int n, x, t;
    
    printf("Plz input n= x= ");
    scanf("%d,%d", &n, &x);
    if (n < 0)
        printf("'n' Must >=0!");
    else
        t = Pnx(n, x);

    printf("Pn(x)=%d", t);
    return 0;
}

int Pnx(int n, int x)
{
    int t;

    switch (n)
    {
    case 0:
        t = 1;
        break;
    case 1:
        t = x;
        break;
    default:
        t = ((2 * n - 1) * x - Pnx(n - 1, x) - (n - 1) * Pnx(n - 2, x)) / n;
        break;
    }
    return t;
}