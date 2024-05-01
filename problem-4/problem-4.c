#include <stdio.h>
#include <stdint.h>

int is_palindrome(int n)
{
    int rev = 0, temp = n;

    while (temp != 0)
    {
        rev = rev * 10 + (temp % 10);
        temp = temp / 10;
    }

    return n == rev ? 1 : 0;
}

int main(void)
{
    int largest_product = 0, i, j, product;

    for (i = 100; i <= 999; i++)
    {
        for (j = 100; j <= 999; j++)
        {
            product = i * j;

            if (is_palindrome(product) && product > largest_product)
            {
                largest_product = product;
            }
        }
    }

    printf("%d \n", largest_product);

    return 0;
}