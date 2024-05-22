#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N 1001

int main(void)
{
    size_t i, j;
    uint32_t **matrix = malloc(sizeof(int **) * N), col, row, n = 1;
    uint64_t sum = 0;

    for (i = 0; i < N; i++)
    {
        matrix[i] = malloc(sizeof(int *) * N);
    }

    col = N / 2;
    row = N / 2;
    matrix[row][col] = n;
    n++;
    while (!(row == 0 && col == N - 1))
    {
        if ((row == N / 2 && col == N / 2) || (row + col == N - 1 && col > N / 2))
        {
            col += 1;
            matrix[row][col] = n;
            n++;
            while (col != row)
            {
                row += 1;
                matrix[row][col] = n;
                n++;
            }
            continue;
        }

        if (col == row && col > N / 2)
        {
            col -= 1;
            matrix[row][col] = n;
            n++;
            while (col + row != N - 1)
            {
                col -= 1;
                matrix[row][col] = n;
                n++;
            }
            continue;
        }

        if (col == row && col < N / 2)
        {
            col += 1;
            matrix[row][col] = n;
            n++;
            while (col + row != N - 1)
            {
                col += 1;
                matrix[row][col] = n;
                n++;
            }
            continue;
        }

        if (row + col == N - 1 && col < N / 2)
        {
            row -= 1;
            matrix[row][col] = n;
            n++;
            while (col != row)
            {
                row -= 1;
                matrix[row][col] = n;
                n++;
            }
            continue;
        }
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i == j || i + j == N - 1)
            {
                sum += matrix[i][j];
            }
        }
    }

    printf("ANSWER: % " PRId64 " \n", sum);

    for (i = 0; i < N; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
