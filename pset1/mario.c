#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i, j, n;
    int min = 0;
    int max = 23;

    do
    {
        printf("Height: ");
        n = GetInt();
    }
    while (n < min || n > max);

    for (i = 2, ++n; i <= n; i++)
    {
        for (j = n; j > i; j--)
        {
            printf(" ");
        }

        for (j = i; j > 0; j--)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}
