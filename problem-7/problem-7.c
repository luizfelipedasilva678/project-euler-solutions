#include <stdio.h>
#define ARR_SIZE 1000000

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
    int primes[ARR_SIZE], prime_count = 0;

    generate_primes(primes);

    for (i = 0; i < ARR_SIZE; i++)
    {
        if (primes[i] == 1)
        {
            prime_count++;
        }

        if (prime_count == 10001)
        {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}