#include <stdio.h>
#include <math.h>

int main(void)
{
    int i, square_of_sum = 0;
    double sum_of_square = 0;

    for (i = 1; i <= 100; i++)
    {
        square_of_sum += i;
        sum_of_square += pow(i, 2);
    }

    printf("Answer: %f\n", pow(square_of_sum, 2) - sum_of_square);

    return 0;
}