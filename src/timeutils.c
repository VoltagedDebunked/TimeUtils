#include "../core/time_utils.h"
#include <time.h>

// Function to print current date and time
void print_current_datetime() {
    time_t current_time;
    struct tm *local_time;

    // Get current time
    current_time = time(NULL);
    local_time = localtime(&current_time);

    // Print formatted date and time
    printf("Current Date and Time: %s", asctime(local_time));
}

// Function to print number of days in a given month of a year
void print_days_in_month(int month, int year) {
    int days_in_month;

    switch (month) {
        case 4: case 6: case 9: case 11:
            days_in_month = 30;
            break;
        case 2:
            if (is_leap_year(year))
                days_in_month = 29;
            else
                days_in_month = 28;
            break;
        default:
            days_in_month = 31;
            break;
    }

    printf("Number of days in month %d of year %d: %d\n", month, year, days_in_month);
}

// Function to check if a year is a leap year
int is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}
