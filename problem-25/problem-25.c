#include <stdio.h>
#include <math.h>
#include <gmp.h>

int count_digits(mpz_t n)
{
    int count = 0;
    mpz_t temp;
    mpz_init(temp);
    mpz_set(temp, n);

    while (mpz_cmp_ui(temp, 0) != 0)
    {
        mpz_tdiv_q_ui(temp, temp, 10);
        count++;
    }

    mpz_clear(temp);
    return count;
}

int main(void)
{
    size_t i;
    mpz_t next, prev;
    mpz_inits(next, prev, NULL);

    for (i = 2; i <= 5000; i++)
    {
        mpz_fib2_ui(next, prev, i);

        if (count_digits(next) == 1000)
        {
            printf("Answer: %zu\n", i);
            break;
        }
    }

    mpz_clears(next, prev, NULL);
    return 0;
}