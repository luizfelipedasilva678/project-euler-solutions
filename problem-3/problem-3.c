#include <stdio.h>
#include <stdint.h>
#define ARR_SIZE 10000

int main(void)
{
    size_t i, j;
    uint64_t n = 600851475143;
    int largest_divisor = 0;
    int primes[ARR_SIZE];

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

    for (i = 2; i < ARR_SIZE; i++)
    {
        if (primes[i] == 1 && n % i == 0)
        {
            largest_divisor = i;
        }
    }

    printf("%d \n", largest_divisor);

    return 0;
}