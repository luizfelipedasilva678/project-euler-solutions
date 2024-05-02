#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#define ARR_SIZE 3000000

void generate_primes(int *primes)
{
    int i, j;

    for (i = 0; i < ARR_SIZE; i++)
    {
        primes[i] = -1;
    }

    for (i = 2; i < ARR_SIZE; i++)
    {
        if (primes[i] == -1)
        {
            primes[i] = 1;

            for (j = i + i; j < ARR_SIZE; j += i)
            {
                primes[j] = 0;
            }
        }
    }
}

int main(void)
{
    int i;
    uint64_t sum = 0;
    int *primes = (int *)malloc(ARR_SIZE * sizeof(int));

    generate_primes(primes);

    for (i = 0; i < ARR_SIZE; i++)
    {

        if (i < 2000000 && primes[i] == 1)
        {
            sum += i;
        }
    }

    printf("%" PRIu64 "\n", sum);

    free(primes);
    return 0;
}