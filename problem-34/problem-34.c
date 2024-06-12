#include <gmp.h>

#define LIMIT 1000000

int main(void) {
    size_t i;
    mpz_t temp, remainder, factorial_result, temp_sum, sum;

    mpz_inits(temp, remainder, factorial_result, temp_sum, sum, NULL);

    for (i = 3; i <= LIMIT; i++) {
        mpz_set_ui(temp, i);

        while (mpz_cmp_ui(temp, 0) != 0) {
            mpz_tdiv_qr_ui(temp, remainder, temp, 10);
            mpz_fac_ui(factorial_result, mpz_get_ui(remainder));
            mpz_add(temp_sum, factorial_result, temp_sum);
        }

        if (mpz_cmp_ui(temp_sum, i) == 0) {
            mpz_add_ui(sum, sum, i);
        }

        mpz_set_ui(temp_sum, 0);
    }

    gmp_printf("Answer: %Zd", sum);

    mpz_clears(temp, remainder, factorial_result, temp_sum, sum, NULL);
    return 0;
}