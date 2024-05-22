#include<stdio.h>
#include<stdlib.h>

#define N 1001

void print_matrix(int ** matrix) {
    int i, j;

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        puts("");
    }
}

int main(void) {
    int col, row, i, n = 1;
    int** matrix = malloc(sizeof(int **) * N);

    for(i = 0; i < N; i++) {
        matrix[i] = malloc(sizeof(int*) * N);
    }

    col = N / 2;
    row = N / 2;
    matrix[row][col] = n;
    n++;
    while(!(row == 0 && col == N - 1)) {
        if((row == N / 2 && col == N / 2) || (row + col == N - 1 && col > N / 2)) {
            col += 1;
            matrix[row][col] = n;
            n++;
            while(col != row) {
                row += 1;
                matrix[row][col] = n;
                n++;
            }
            continue;
        }

        if(col == row && col > N / 2) {
            col -= 1;
            matrix[row][col] = n;
            n++;
            while(col + row != N - 1) {
                col -= 1;
                matrix[row][col] = n;
                n++;
            }
            continue;
        }

        if(col == row && col < N / 2) {
            col += 1;
            matrix[row][col] = n;
            n++;
            while(col + row != N - 1) {
                col += 1;
                matrix[row][col] = n;
                n++;
            }
            continue;
        }

        if(row + col == N - 1 && col < N / 2) {
            row -= 1;
            matrix[row][col] = n;
            n++;
            while(col != row) {
                row -= 1;
                matrix[row][col] = n;
                n++;
            }
            continue;
        }
    }


    print_matrix(matrix);

    for(i = 0; i < N; i++) {
        free(matrix[i]);
    }

    free(matrix);
    return 0;
}
