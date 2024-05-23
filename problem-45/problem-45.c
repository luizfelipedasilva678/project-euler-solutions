#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

// Need to be improved

#define LIMIT 100000

uint64_t triangular_numbers[LIMIT];
uint64_t pentagonal_numbers[LIMIT];
uint64_t hexagonal_numbers[LIMIT];

int cmpfunc(const void * a, const void * b) {
   return ( *(uint64_t*)a - *(uint64_t*)b );
}

uint64_t find_next_triangular_pentagonal_hexagonal_number() {
    size_t i, j, k;

    for(i = 285; i < LIMIT; i++) {
        for(j = 165; j < LIMIT; j++) {
            if(triangular_numbers[i] == pentagonal_numbers[j]) {
                for(k = 143; k < LIMIT; k++) {
                    if(hexagonal_numbers[k] == pentagonal_numbers[j]) return hexagonal_numbers[k];
                }
            }
        }
    }

    return 0;
}

int main(void) {
    size_t i;
    uint64_t pentagonal_n, triangular_n, hexagonal_n, n;

    for(i = 0; i < LIMIT; i++) {
        triangular_n = ((i + 1) * ((i + 1) + 1)) / 2;
        pentagonal_n = ((i + 1) * ((i + 1) * 3 - 1)) / 2;
        hexagonal_n = (i + 1) * (2 * (i + 1) - 1);

        triangular_numbers[i] = triangular_n;
        pentagonal_numbers[i] = pentagonal_n;
        hexagonal_numbers[i] = hexagonal_n;
    }

    n = find_next_triangular_pentagonal_hexagonal_number();

    printf("%"PRIu64"", n);

    return 0;
}
