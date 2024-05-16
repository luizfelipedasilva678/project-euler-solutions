#include<stdio.h>
#include<math.h>
#include<inttypes.h>
#define N 28123

int abundant_numbers[N] = {0};

int sum_divisors(int n) {
    int sum = 1, i;

    for(i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            sum += i;

            if(i != n/i)
                sum += n/i;
        }
    }

    return sum;
}

int is_abundant(int n) {
    if(sum_divisors(n) > n) {
        return 1;
    }

    return 0;
}

int main(void) {
    int i, j, k;
    int sum_abundant_numbers[N + 1] = {0};
    uint64_t sum;

    j = 0;
    for(i = 12; i <= N; i++) {
        if(is_abundant(i)) {
            abundant_numbers[j] = i;
            j++;
        }

    }

    for(i = 0; i < j; i++) {
        for(k = i; k < j; k++) {
           if((abundant_numbers[i] +  abundant_numbers[k]) <= N) {
                sum_abundant_numbers[abundant_numbers[i] +  abundant_numbers[k]] = 1;
           }
        }
    }

    sum = 0;
    for(i = 0; i < N + 1; i++) {
        if(sum_abundant_numbers[i] == 0)
            sum += i;
    }

    printf("Answer: %d ", sum);


    return 0;
}
