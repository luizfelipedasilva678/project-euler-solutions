#include <stdio.h>

int main(void)
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int ways[201] = {0};
    ways[0] = 1;

    for (int j = 0; j < sizeof(coins) / sizeof(coins[0]); j++)
    {
        for (int i = 1; i <= 200; i++)
        {
            if (i - coins[j] >= 0)
            {
                ways[i] += ways[i - coins[j]];
            }
        }
    }

    printf("%d\n", ways[200]);
    return 0;
}