#include <stdio.h>
#include <cs50.h>

/* Calculate the number of U.S. coins returned as change */
int main(void)
{
    const int NUM_COINS = 4;

    float n;
    int cents = 0, change = 0, i = 0, min = 0;
    int coins[NUM_COINS] = {25, 10, 5, 1};

    /* Get the amount of change needed */
    do
    {
        printf("o hai! how much change is owed?\n");
        n = GetFloat();
    }
    while (n < min);

    /* Convert change needed into cents */
    cents = (int) ((n * 100) + 0.5);

    /* Calculate how many coins needed to make change */
    for (i = 0; i < NUM_COINS; i++)
    {
        change += cents / coins[i];
        cents = cents % coins[i];
    }

    printf("%d\n", change);

    return 0;
}
