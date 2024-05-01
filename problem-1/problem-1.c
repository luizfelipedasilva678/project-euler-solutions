#include <stdio.h>

int main(void)
{
    int sum = 0, count = 1000, i;

    for (i = 1; i < count; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }

    printf("%d\n", sum);
    return 0;
}