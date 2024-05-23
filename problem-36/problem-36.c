#include<stdio.h>
#include<inttypes.h>

#define MAX_DIGITS_BINARY 20

void swap(uint32_t *arr, size_t i, size_t j) {
    uint32_t temp;

    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void reverse(uint32_t *arr, size_t length) {
    size_t i, j, middle;

    i = 0;
    j = length - 1;
    middle = length / 2;
    while(i < middle) {
        swap(arr, i, j);
        i++;
        j--;
    }
}

void base10_to_base2(uint32_t n, uint32_t *base2_n, size_t *idx_number) {
    size_t i;
    uint32_t temp;

    *idx_number = 0;
    temp = n;
    while(temp != 1) {
        base2_n[*idx_number] = temp % 2;
        (*idx_number)++;
        temp /= 2;
    }
    base2_n[*idx_number] = temp;
    (*idx_number)++;

    reverse(base2_n, *idx_number);
}

uint8_t is_palindrome_base2(uint32_t n)
{
    size_t idx_number, i;
    uint32_t base2_n[MAX_DIGITS_BINARY], reversed_base2_n[MAX_DIGITS_BINARY];

    base10_to_base2(n, base2_n, &idx_number);

    for(i = 0; i < idx_number; i++) {
       reversed_base2_n[i] = base2_n[i];
    }

    reverse(reversed_base2_n, idx_number);

    for(i = 0; i < idx_number; i++) {
        if(base2_n[i] != reversed_base2_n[i]) return 0;
    }

    return 1;
}

uint8_t is_palindrome_base10(uint32_t n)
{
    uint32_t rev = 0, temp = n;

    while (temp != 0)
    {
        rev = rev * 10 + (temp % 10);
        temp = temp / 10;
    }

    return n == rev ? 1 : 0;
}

uint8_t is_palindrome_both_bases(uint32_t n) {
    if(is_palindrome_base2(n) && is_palindrome_base10(n)) {
        return 1;
    }

    return 0;
}

int main(void) {
    size_t i;
    uint32_t sum;

    sum = 0;
    for(i = 1; i <= 999999; i++) {
        if(is_palindrome_both_bases(i)) {
            sum += i;
        }
    }

    printf("%"PRIu32"", sum);

    return 0;
}
