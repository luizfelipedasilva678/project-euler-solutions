#include<stdio.h>
#include<math.h>
#include<inttypes.h>

// Not such a good solution, but it works.

int sum_divisors(int n) {
    int sum = 1, i;

    for(i = 2; i < sqrt(n); i++) {
        if(n % i == 0) {
            sum += i;

            if(n / i != i)
                sum += n / i;
        }
    }

    return sum;
}

int is_amicable(int a, int b) {
    if(sum_divisors(a) == b && sum_divisors(b) == a) return 1;

    return 0;
}

int main(void) {
    int i, j;
    uint64_t sum = 0;

    for(i = 220; i <= 10000; i++) {
        for(j = i + 1; j <= 10000; j++) {
            if(is_amicable(i, j)) {
                sum += i + j;
            }
        }
    }

    printf("Answer: % "PRIu64" ", sum);

    return 0;
}
