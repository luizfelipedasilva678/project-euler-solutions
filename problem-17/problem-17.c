#include <stdio.h>
#define SIZE 99

int num_letters_1_to_99[SIZE] = { 3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8,6,9,9,11,10,10,9,11,11,10,6,9,9,11,10,10,9,11,11,10,5,8,8,10,9,9,8,10,10,9,5,8,8,10,9,9,8,10,10,9,5,8,8,10,9,9,8,10,10,9,7,10,10,12,11,11,10,12,12,11,6,9,9,11,10,10,9,11,11,10,6,9,9,11,10,10,9,11,11,10 };

int main(void) {
    int i, sum = 0, n;

    for(int i = 1; i <= 999; i++) {
        if(i >= 1 && i <= 99) {
            sum += num_letters_1_to_99[i - 1];
        }

        if(i == 100) {
            sum += num_letters_1_to_99[0] + 7;
        }

        if(i == 200) {
            sum += num_letters_1_to_99[1] + 7;
        }

        if(i == 300) {
            sum += num_letters_1_to_99[2] + 7;
        }

        if(i == 400) {
            sum += num_letters_1_to_99[3] + 7;
        }

        if(i == 500) {
            sum += num_letters_1_to_99[4] + 7;
        }

        if(i == 600) {
            sum += num_letters_1_to_99[5] + 7;
        }

        if(i == 700) {
            sum += num_letters_1_to_99[6] + 7;
        }

        if(i == 800) {
            sum += num_letters_1_to_99[7] + 7;
        }

        if(i == 900) {
            sum += num_letters_1_to_99[8] + 7;
        }

        if(i >= 101 && i <= 199) {
            if(i - 100 - 1 >= 0) {
                sum += num_letters_1_to_99[0] + num_letters_1_to_99[i - 100 - 1] + 10;
            }
        }

        if(i >= 201 && i <= 299) {
            if(i - 200 - 1 >= 0) {
                sum += num_letters_1_to_99[1] + num_letters_1_to_99[i - 200 - 1] + 10;
            }
        }

        if(i >= 301 && i <= 399) {
            if(i - 300 - 1 >= 0) {
                sum += num_letters_1_to_99[2] + num_letters_1_to_99[i - 300 - 1] + 10;
            }
        }

        if(i >= 401 && i <= 499) {
            if(i - 400 - 1 >= 0) {
                sum += num_letters_1_to_99[3] + num_letters_1_to_99[i - 400 - 1] + 10;
            }
        }

        if(i >= 501 && i <= 599) {
            if(i - 500 - 1 >= 0) {
                sum += num_letters_1_to_99[4] + num_letters_1_to_99[i - 500 - 1] + 10;
            }
        }

        if(i >= 601 && i <= 699) {
            if(i - 600 - 1 >= 0) {
                sum += num_letters_1_to_99[5] + num_letters_1_to_99[i - 600 - 1] + 10;
            }
        }

        if(i >= 701 && i <= 799) {
            if(i - 700 - 1 >= 0) {
                sum += num_letters_1_to_99[6] + num_letters_1_to_99[i - 700 - 1] + 10;
            }
        }

        if(i >= 801 && i <= 899) {
            if(i - 800 - 1 >= 0) {
                sum += num_letters_1_to_99[7] + num_letters_1_to_99[i - 800 - 1] + 10;
            }
        }

        if(i >= 901 && i <= 999) {
            if(i - 900 - 1 >= 0) {
                sum += num_letters_1_to_99[8] + num_letters_1_to_99[i - 900 - 1] + 10;
            }
        }
    }


    sum += 11;
    printf("\nSUM: %d \n", sum);

    return 0;
}

