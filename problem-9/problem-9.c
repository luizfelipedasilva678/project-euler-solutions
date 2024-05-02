#include <stdio.h>

// TODO: Improve algorithm

int special_pythagorean_triplet()
{
    int a, b, c, result = 0;

    for (a = 1; a < 1000; a++)
    {
        for (b = a + 1; b < 1000; b++)
        {
            for (c = b + 1; c < 1000; c++)
            {
                if (a * a + b * b == c * c && a + b + c == 1000)
                {
                    result = a * b * c;
                }
            }
        }
    }

    return result;
}

int main(void)
{
    printf("%d\n", special_pythagorean_triplet());

    return 0;
}
