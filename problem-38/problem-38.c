#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LIMIT 100000

int cmpfunc( const void *a, const void *b) {
  return *(char*)a - *(char*)b;
}

int value_exists_in_array(int n, size_t idx_products,int arr[]) {
    size_t i;

    for(i = 0; i < idx_products; i++) {
        if(arr[i] == n) return 1;
    }

    return 0;
}

int digits(int n) {
    return floor(log10(abs(n))) + 1;
}

int is_pandigital_product(int a, int b) {
    char str[10];
    snprintf(str, 10, "%d%d%d", a, b, a*b);
    qsort(str, 9, sizeof(char), cmpfunc);

    return strcmp(str, "123456789") == 0;
}

int main(void) {
    int products[LIMIT] = {0};
    int *item, product, sum, digits_cnt;
    size_t i, j, idx_products;

    idx_products = 0;
    for(i = 0; i <= LIMIT; i++) {
        for (j = 0; j <= LIMIT; j++) {
            digits_cnt = digits(i) + digits(j) + digits(i * j);
            if(digits_cnt == 9) {
                if(is_pandigital_product(i, j) == 1) {
                    product = i * j;

                    if(value_exists_in_array(product, idx_products, products) == 0) {
                        products[idx_products] = product;
                        idx_products++;
                    }
                }
            }
        }
    }

    sum = 0;
    for(i = 0; i < idx_products; i++) {
        sum += products[i];
    }

    printf("Answer: %d \n", sum);

    return 0;
}
