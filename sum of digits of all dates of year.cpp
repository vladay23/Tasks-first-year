#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    cout << "Введите год: ";
    int i = 0;
    int year = 0, sum_year = 0, kol_days = 366;
    int february = 28;
    int sum_days_31 = 0, sum_days_30 = 0, sum_days_29 = 0, sum_days_28 = 0;
    int total_days = 0, total = 0, total_year = 0, total_month = 0;
    cin >> year;
    //leap year check -> number of days in February
    if (year % 4 == 0 or ((year % 100 == 0) and (year % 400 == 0))) {
        february = 29;
    }
    //the sum of the digits in the year in the module, just in case
    while (year != 0) {
        sum_year = sum_year + year % 10; 
        year = year / 10;
    }
    sum_year = abs(sum_year);
    //the sum of days for 31, 30, 29 and 28 days in a month
    for (i = 1; i <= 31; i++) {
        sum_days_31 = sum_days_31 + (i % 10 + i / 10);
        switch(i) {
            case 30: sum_days_30 = sum_days_31; break;
            case 29: sum_days_29 = sum_days_31; break;
            case 28: sum_days_28 = sum_days_31; break;
        }
    }
    //number of days per year depending on the leap year
    if (february == 28) {
        sum_days_29 = 0;
        kol_days = 365;
    }
    else sum_days_28 = 0;
    //the sum of the digits of the months up to and including July
    for (i = 1; i <= 7; i++) {
        if (i % 2 != 0) total_month = total_month + (i * 31);
        else if (i % 2 == 0 and i != 2) total_month = total_month + (i * 30);
    }
    //the sum of the digits of the months after June inclusive
    for (i = 8; i <= 12; i++) {
        if (i % 2 == 0) total_month = total_month + (i % 10 + i / 10) * 31;
        else if (i % 2 != 0) total_month = total_month + (i % 10 + i / 10) * 30;
    }
    //the sum of the digits of all days in a year
    total_days = sum_days_28 + sum_days_29 + sum_days_30 * 4 + sum_days_31 * 7;
    //the sum of the digits of all dates by year
    total_year = kol_days * sum_year;
    total = total_days + total_year + total_month + february * 2;
    //check: cout << " " << total_days << " " << total_year << " " << total_month+february*2;
    cout << total;

    return 0;
}
