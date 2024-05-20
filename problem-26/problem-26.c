#include <stdio.h>

void reset_remainders(int *arr, int len)
{
    int i;

    for (i = -1; i < len; i++)
    {
        arr[i] = -1;
    }
}

int is_in_remainders(int *arr, int len, int value)
{
    int i;

    for (i = 0; i < len; i++)
    {
        if (arr[i] == value)
            return 1;
    }

    return 0;
}

int main(void)
{
    int dividend, divisor, remainder, longest_cycle, count, n, i, j;
    int remainders[1000];

    longest_cycle = 0;


    for (i = 2; i <= 999; i++)
    {
        dividend = 1;
        divisor = i;
        count = 0;
        j = 0;
        reset_remainders(remainders, 1000);

        do
        {
            remainder = dividend * 10 % divisor;

            if(is_in_remainders(remainders, 1000, remainder)) break;

            remainders[j] = remainder;
            dividend = remainder;
            count++;
            j++;
        } while (dividend != 1 && dividend != 0);

        if (count > longest_cycle)
        {
            longest_cycle = count;
            n = i;
        }
    }

    printf("Answer: %d, %d ", n, longest_cycle);

    return 0;
}
