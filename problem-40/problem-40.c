#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 5000000

int char_to_int(char c)
{
    return c - '0';
}

int main(void)
{
    char *str = (char *)malloc(sizeof(char *) * MAX_LENGTH), *p;
    int offset = 0;
    size_t i;

    p = str;

    for (i = 1; i <= MAX_LENGTH; i++)
    {
        offset += snprintf(p + offset, MAX_LENGTH - offset, "%zu", i);
    }

    printf("\nAnswer: %d\n", char_to_int(str[0]) * char_to_int(str[9]) * char_to_int(str[99]) * char_to_int(str[999]) * char_to_int(str[9999]) * char_to_int(str[99999]) * char_to_int(str[999999]));

    free(str);
    return 0;
}