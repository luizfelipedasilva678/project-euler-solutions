#include <stdio.h>
#include <inttypes.h>

int is_even(int n)
{
    return n % 2 == 0 ? 1 : 0;
}

int main(void)
{
    uint64_t temp, count, start_number, largest_count = 0;

    for (int i = 999999; i >= 1; i--)
    {
        temp = i;
        count = 1;

        while (temp != 1)
        {
            if (is_even(temp))
            {
                temp = temp / 2;
            }
            else
            {
                temp = temp * 3 + 1;
            }

            count++;
        }

        if (count > largest_count)
        {
            start_number = i;
            largest_count = count;
        }
    }

    printf("Count: %" PRIu64 "\n", start_number);

    return 0;
}