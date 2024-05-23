#include <stdio.h>
#include <inttypes.h>
#include <gmp.h>

int main(void)
{
    size_t i;
    mpz_t q, r, d, temp, sum, power_result, sum_all_terms;
    mpz_inits(q, r, d, temp, sum_all_terms, sum, power_result, NULL);
    mpz_set_ui(d, 10);
    mpz_set_ui(sum, 0);

    for (i = 2; i <= 1000000; i++)
    {
        mpz_set_ui(temp, i);
        mpz_set_ui(sum, 0);
        while (mpz_cmp_ui(temp, 0) != 0)
        {
            mpz_tdiv_qr(q, r, temp, d);
            mpz_set(temp, q);
            mpz_pow_ui(power_result, r, 5);
            mpz_add(sum, sum, power_result);
        }

        if (mpz_cmp_ui(sum, i) == 0)
        {
            mpz_add_ui(sum_all_terms, sum_all_terms, i);
        }
    }

    gmp_printf("%Zd\n", sum_all_terms);

    mpz_clears(q, r, d, temp, sum_all_terms, sum, power_result, NULL);
    return 0;
}