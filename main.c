#include <stdio.h>
#include <stdbool.h>

// global variables
int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// functions
bool is_leap_year(int);
void add_days_to_date(int*, int*, int*, int);

bool is_leap_year(int year) {
    return (year % 4 == 0 && (year % 100 || year % 400 == 0));
}

void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add) {
    int days_left_in_month;

    while (days_left_to_add > 0) {
        days_left_in_month = days_in_month[*mm] - *dd;

        if (*mm == 2 && is_leap_year(*yy)) {
            days_left_in_month++;

        }

        if (days_left_to_add > days_left_in_month) {
            days_left_to_add -= (days_left_in_month + 1); // -1 for next month
            *dd = 1;                                      // 1. of new month

            // if december happy new year else next month
            if (*mm == 12) {
                *mm = 1;
                *yy += 1;
            } else {
                *mm += 1;
            }

        } else {
            *dd += days_left_to_add;
            days_left_to_add = 0;
        }
    }
}

int main(void) {
    int mm;
    int dd;
    int yy;
    int days_left_to_add;

    printf("Pelase enter a date between the years 1800 and 10000 in the format mm dd yy and provide the number of days to add to this date:\n");
    scanf("%d%d%d%d", &mm, &dd, &yy, &days_left_to_add);

    add_days_to_date(&mm, &dd, &yy, days_left_to_add);
    printf("%d/%d/%d\n", mm, dd, yy);

    return 0;
}