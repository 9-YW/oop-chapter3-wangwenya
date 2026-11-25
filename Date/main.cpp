#include "Date.h"

#include <iostream>

int main() {
    int year = 0;
    int month = 0;
    int day = 0;

    std::cout << "Enter date (year month day): ";
    if (!(std::cin >> year >> month >> day)) {
        std::cerr << "Error: invalid input format.\n";
        return 1;
    }

    Date date(year, month, day);
    const int weekday = date.calWeekday();

    std::cout << "Date: ";
    date.display();
    std::cout << "Weekday: "
              << (weekday == 0 ? "星期日" :
                  weekday == 1 ? "星期一" :
                  weekday == 2 ? "星期二" :
                  weekday == 3 ? "星期三" :
                  weekday == 4 ? "星期四" :
                  weekday == 5 ? "星期五" : "星期六")
              << '\n';

    std::cout << "\n-- Leap year and next-day test --\n";
    Date leapDay(2024, 2, 28);
    std::cout << "2024 is leap year: " << (leapDay.isLeapYear() ? "yes" : "no") << '\n';
    std::cout << "Before nextDay: ";
    leapDay.display();
    leapDay.nextDay();
    std::cout << "After  nextDay: ";
    leapDay.display();

    std::cout << "\n-- Invalid setter test --\n";
    date.setMonth(2);
    date.setDay(30);
    std::cout << "Date after rejected setDay(30): ";
    date.display();

    Date yearEnd(2026, 12, 31);
    yearEnd.nextDay();
    std::cout << "After 2026-12-31 nextDay: ";
    yearEnd.display();

    Date manual;
    manual.Init(2024, 2, 29);
    std::cout << "Init(2024, 2, 29): ";
    manual.display();
    std::cout << "Getters: " << manual.getYear() << ' '
              << manual.getMonth() << ' ' << manual.getDay() << '\n';

    std::cout << "Invalid constructor 2025-02-29: ";
    Date invalid(2025, 2, 29);
    invalid.display();

    return 0;
}
