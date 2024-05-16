#include<stdio.h>

int is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 != 0)
                return 0;
        }

        return 1;
    }

    return 0;
}

int days_in_month(int month, int year) {
    int days;

    days = 28;

    if (is_leap_year(year)) {
        days = 29;
    }

    switch (month) {
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
    }

    return days;
}

int main(void) {
    int i, j, k, quantity_of_days, day_of_week = 0, quantity_of_sundays = 0;

    for(i = 1900; i <= 2000; i++) {
        for(j = 1; j <= 12; j++) {
            quantity_of_days = days_in_month(j, i);

            for(k = 1; k <= quantity_of_days; k++) {
                day_of_week++;

                if(day_of_week == 7) {
                    if(k == 1 && i != 1900)
                        quantity_of_sundays++;
                    day_of_week = 0;
                }
            }
        }
    }

    printf("Answer: %d", quantity_of_sundays);

    return 0;
}
