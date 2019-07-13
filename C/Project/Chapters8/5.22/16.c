#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 512

int main()
{
    void Process(char c[]);
    void Save(char c[]);
    char c[SIZE];

    printf("Plz enter something: ");
    gets(c);

    Process(c);
    Save(c);
    return 0;
}

void Process(char word[])
{
    int len = strlen(word);
    char *p;
    int i;

    p = word;
    for (i = 0; i < len; i++)
    {
        if ((*p <= '0') && (*p >= '9'))
        {
            *p = ' ';
        }
        p++;
    }
    *p = ' ';
}

void Save(char word[])
{
    int len = strlen(word);
    char save[len], *p;
    int a[len], x = 0, y = 0, z = 0, i, j;

    p = word;
    for (i = 0; i < len; i++)
    {
        if ((*p >= '0') && (*p <= '9'))
        {
            save[x] = *p;
            x++;
            y++;
        }
        else
        {
            if (y > 0)
            {
                a[z] = atoi(save);
                z++;

                memset(save, 0, sizeof(save));
                x = 0;
                y = 0;
            }
        }
        p++;
    }

    printf("There are %d Number: \n", z);
    for (j = 0; j < z; j++)
    {
        printf("%d ", a[j]);
    }
}