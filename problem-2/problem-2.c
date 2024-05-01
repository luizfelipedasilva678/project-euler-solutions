#include <stdio.h>
#include <stdint.h>
#define MAX 4000000

int is_even(int n)
{
    return n % 2 == 0 ? 1 : 0;
}

void sum_even_fibs(int *result)
{
    int prev = 1, next = 2, sum = 0;

    while (prev < MAX)
    {
        if (is_even(prev))
        {
            sum += prev;
        }

        next = prev + next;
        prev = next - prev;
    }

    *result = sum;
}

int main(void)
{
    int result;

    sum_even_fibs(&result);

    printf("%d\n", result);
    return 0;
}