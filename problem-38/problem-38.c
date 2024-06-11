#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define LIMIT 10000

int digits(int n) { return floor(log10(abs(n))) + 1; }

int cmpfunc(const void *a, const void *b) { return *(char *)a - *(char *)b; }

int main(void) {
    int numbers[LIMIT] = {0}, digits_cnt, idx_numbers, offset, n, largest_n;
    char buff[10], temp[10], *p;
    size_t i, j, k;

    largest_n = 0;
    for (i = 1; i < LIMIT; i++) {
        digits_cnt = 0;
        idx_numbers = 0;
        for (j = 1; j < LIMIT; j++) {
            if (digits_cnt > 9) break;

            digits_cnt += digits(i * j);
            numbers[idx_numbers] = i * j;
            idx_numbers++;

            if (digits_cnt == 9) {
                offset = 0;
                p = buff;
                n = 0;

                for (k = 0; k < idx_numbers; k++) {
                    offset +=
                        snprintf(p + offset, 10 - offset, "%d", numbers[k]);
                }

                strcpy(temp, buff);
                qsort(temp, 9, sizeof(char), cmpfunc);

                if (strcmp(temp, "123456789") == 0) {
                    sscanf(buff, "%d", &n);

                    if (n > largest_n) {
                        largest_n = n;
                    }
                }
            }
        }
    }

    printf("%d ", largest_n);

    return 0;
}
