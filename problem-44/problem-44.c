#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

#define LIMIT 10000

uint32_t pentagon_numbers[LIMIT];

int cmpfunc(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(void) {
    uint32_t *is_sum_pentagon, *is_diff_pentagon, sum, diff;
    uint8_t found;
    size_t i, j;


    for(i = 0; i < LIMIT; i++) {
       pentagon_numbers[i] = (i + 1)*(3*(i + 1)-1)/2;
    }

    found = 0;
    for(i = 0; i < LIMIT; i++) {
        for(j = i + 1; j < LIMIT; j++) {
            sum = pentagon_numbers[i] + pentagon_numbers[j];
            diff = abs(pentagon_numbers[i] - pentagon_numbers[j]);
            is_sum_pentagon = (uint32_t*) bsearch(&sum, pentagon_numbers, LIMIT, sizeof(uint32_t), cmpfunc);
            is_diff_pentagon = (uint32_t*) bsearch(&diff, pentagon_numbers, LIMIT, sizeof(uint32_t), cmpfunc);

            if(is_sum_pentagon != NULL && is_diff_pentagon != NULL) {
                found = 1;
                break;
            }
        }

        if(found == 1) break;
    }

    printf("%"PRIu32" \n", abs( pentagon_numbers[i] - pentagon_numbers[j] ));

    return 0;
}
