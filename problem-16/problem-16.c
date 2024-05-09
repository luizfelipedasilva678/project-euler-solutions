#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#define SIZE 302

void multiply_by_two(int *digits)
{
    int carry = 0;

    for (int i = 0; i < SIZE; i++)
    {
        int prod = digits[i] * 2 + carry;
        digits[i] = prod % 10;
        carry = prod / 10;
    }
}

int sum_of_digits(int *digits)
{
    int sum = 0;

    for (int i = 0; i < SIZE; i++)
    {
        sum += digits[i];
    }

    return sum;
}

int main()
{
    int digits[SIZE] = {0};
    digits[0] = 1;

    for (int i = 0; i < 1000; i++)
    {
        multiply_by_two(digits);
    }

    printf("%d \n", sum_of_digits(digits));

    return 0;
}
