#include <stdio.h>
#define SIZE 512

int main()
{
    void Move(int a[], int n, int m);
    int a[SIZE];
    int i, n, m;

    printf("你要扣几个数?: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
    {
        printf("Plz input number %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("你要换几个数字?:");
    scanf("%d", &m);

    Move(a, n, m);

    printf("换后的数组为：");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

void Move(int a[], int n, int m)
{
    int save[m];
    int i, x = 0;

    for (i = n - m; i < n; i++)
    {
        save[x] = a[i];
        x++;
    }
    for (i = n - 1; i >= m; i--)
    {
        a[i] = a[i - m];
    }
    for (i = 0; i < m; i++)
    {
        a[i] = save[i];
    }
}