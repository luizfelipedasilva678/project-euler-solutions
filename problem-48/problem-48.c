#include <gmp.h>

int main(void)
{

    size_t i;
    mpz_t sum, pow_result;
    mpz_inits(sum, pow_result, NULL);

    for (i = 1; i <= 1000; i++)
    {
        mpz_ui_pow_ui(pow_result, i, i);
        mpz_add(sum, sum, pow_result);
    }

    gmp_printf("%Zd\n", sum);

    mpz_clears(sum, pow_result, NULL);
    return 0;
}