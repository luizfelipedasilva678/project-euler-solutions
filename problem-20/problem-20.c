#include <gmp.h>
#include <stdio.h>

int main(void)
{
    int sum = 0;
    mpz_t n;
    mpz_init(n);
    mpz_set_ui(n, 1);

    for (int i = 100; i >= 1; i--)
    {
        mpz_mul_ui(n, n, i);
    }

    while (mpz_cmp_ui(n, 0) != 0)
    {
        sum += mpz_fdiv_ui(n, 10);
        mpz_tdiv_q_ui(n, n, 10);
        gmp_printf("%zu\n", mpz_fdiv_ui(n, 10));
    }

    mpz_clear(n);
    return 0;
}