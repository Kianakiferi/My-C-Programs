#include <stdio.h>
#define SIZE 10

int main()
{
    float average(float array[SIZE]);
    float score[SIZE], aver;
    int i;

    for (i = 0; i < SIZE; i++)
    {
        printf("Input scores %d: ", i + 1);
        scanf("%f", &score[i]);
    }
    aver = average(score);
    printf("\naverage score is %5.2f\n", aver);
    return 0;
}

float average(float array[SIZE])
{
    int i;
    float aver, sum = array[0];
    for (i = 1; i < SIZE; i++)
        sum = sum + array[i];
    aver = sum / 10;
    return aver;
}