#include <stdio.h>
#include <gmp.h>
#include <inttypes.h>

#define N 9604

uint8_t value_exists(mpz_t arr[], mpz_t n)
{
    size_t i;

    for (i = 0; i < N; i++)
    {
        if (mpz_cmp(arr[i], n) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int main(void)
{
    size_t i, j, idx_results_arr = 0, different_terms_cnt = 0;
    mpz_t a, b, pow_result, results[N];
    mpz_inits(a, b, pow_result, NULL);
    mpz_set_ui(a, 2);
    mpz_set_ui(b, 2);

    for (i = 0; i < N; i++)
    {
        mpz_init(results[i]);
    }

    for (i = 2; i <= 100; i++)
    {
        for (j = 2; j <= 100; j++)
        {
            mpz_ui_pow_ui(pow_result, i, j);

            if (!value_exists(results, pow_result))
            {
                mpz_set(results[idx_results_arr], pow_result);
                idx_results_arr++;
                different_terms_cnt++;
            }
        }
    }

    for (i = 0; i < N; i++)
    {
        mpz_clear(results[i]);
    }

    printf("%zu\n", different_terms_cnt);

    mpz_clears(a, b, pow_result, NULL);
    return 0;
}