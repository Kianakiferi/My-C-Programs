#include <stdio.h>

int main()
{
    int max(float x, float y);
    float a, b;
    int c;
    
    printf("Plz type 3 numbers like: 1 2 3\n");
    scanf("%f %f", &a, &b);
    c = max(a, b);
    printf("max is %f\n", c);
    return 0;
}

int max(float x, float y)
{
    float z;
    z = x > y ? x : y;
    return z;
}