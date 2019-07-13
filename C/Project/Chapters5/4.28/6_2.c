#include <stdio.h>

int main()
{
    int x, m1 = 0, m2 = 0, m3 = 0, n = 1, n2 = 1, i, k = 0;

    printf("Plz input data: ");
    scanf("%d", &x);
    m1 = x;
    for (i = 1; i < 20; i++)
    {
        printf("Plz input data: ");
        scanf("%d", &x);
        m2 = x;
        if (m2 > m1)
        {
            m1 = m2;
            n = i + 1;
        }
        if (k == 1)
        {
            if (m2 < m3)
            {
                m3 = m2;
                n2 = i + 1;
            }
        }
        else
        {
            if (m2 < m1)
            {
                m3 = m2;
                k = 1;
            }
        }
    }
    printf("Max= %d, Number= %d\nMin= %d, Number= %d\n", m1, n, m3, n2);
    return 0;
}