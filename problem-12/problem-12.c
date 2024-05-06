#include <stdio.h>
#include <inttypes.h>
#define ARR_SIZE 3000000

int primes[ARR_SIZE];

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

int get_divisors(uint64_t n)
{
    int i, divisors = 1, expoent = 0;
    uint64_t aux = n;

    for (i = 2; i < ARR_SIZE; i++)
    {
        if (primes[i] == 1)
        {
            while (aux % i == 0)
            {
                aux /= i;
                expoent++;
            }

            divisors *= expoent + 1;
            expoent = 0;
        }

        if (aux == 1)
            break;
    }

    return divisors;
}

int main(void)
{
    int i = 1;
    uint64_t n;
    generate_primes(primes);

    do
    {
        n = i * (i + 1) / 2;
        i++;
        printf("%" PRId64 " %d \n ", n, get_divisors(n));
    } while (get_divisors(n) < 500);

    return 0;
}