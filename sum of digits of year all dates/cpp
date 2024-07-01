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
    //проверка на високосность года -> кол-ство дней в феврале
    if (year % 4 == 0 or ((year % 100 == 0) and (year % 400 == 0))) {
        february = 29;
    }
    //сумма цифр в году в модуле на всякий случай
    while (year != 0) {
        sum_year = sum_year + year % 10; 
        year = year / 10;
    }
    sum_year = abs(sum_year);
    //сумма дней для 31, 30, 29 и 28 дней в месяце
    for (i = 1; i <= 31; i++) {
        sum_days_31 = sum_days_31 + (i % 10 + i / 10);
        switch(i) {
            case 30: sum_days_30 = sum_days_31; break;
            case 29: sum_days_29 = sum_days_31; break;
            case 28: sum_days_28 = sum_days_31; break;
        }
    }
    //кол-ство дней в году в зависимости от високосности
    if (february == 28) {
        sum_days_29 = 0;
        kol_days = 365;
    }
    else sum_days_28 = 0;
    //сумма цифр месяцев до июля включительно
    for (i = 1; i <= 7; i++) {
        if (i % 2 != 0) total_month = total_month + (i * 31);
        else if (i % 2 == 0 and i != 2) total_month = total_month + (i * 30);
    }
    //сумма цифр месяцев после июня включительно
    for (i = 8; i <= 12; i++) {
        if (i % 2 == 0) total_month = total_month + (i % 10 + i / 10) * 31;
        else if (i % 2 != 0) total_month = total_month + (i % 10 + i / 10) * 30;
    }
    //сумма цифр всех дней в году
    total_days = sum_days_28 + sum_days_29 + sum_days_30 * 4 + sum_days_31 * 7;
    //сумма цифр всех дат по году
    total_year = kol_days * sum_year;
    total = total_days + total_year + total_month + february * 2;
    //проверка: cout << " " << total_days << " " << total_year << " " << total_month+february*2;
    cout << total;

    return 0;
}
