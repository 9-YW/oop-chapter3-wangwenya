#include "Date.h"

#include <iostream>

namespace {
const char* const WEEKDAY_NAMES[] = {
    "星期日", "星期一", "星期二", "星期三",
    "星期四", "星期五", "星期六"
};
}

Date::Date(int y, int m, int d)
    : year(y), month(m), day(d) {
    if (!isValidDate(year, month, day)) {
        std::cout << "Error: invalid date, reset to 1900-01-01.\n";
        resetToDefault();
    }
}

void Date::Init(int y, int m, int d) {
    if (!isValidDate(y, m, d)) {
        std::cout << "Error: invalid date, object reset to 1900-01-01.\n";
        resetToDefault();
        return;
    }

    year = y;
    month = m;
    day = d;
}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

void Date::setYear(int y) {
    if (!isValidDate(y, month, day)) {
        std::cout << "Error: invalid year, value ignored.\n";
        return;
    }
    year = y;
}

void Date::setMonth(int m) {
    if (!isValidDate(year, m, day)) {
        std::cout << "Error: invalid month for current date, value ignored.\n";
        return;
    }
    month = m;
}

void Date::setDay(int d) {
    if (!isValidDate(year, month, d)) {
        std::cout << "Error: invalid day for current month, value ignored.\n";
        return;
    }
    day = d;
}

void Date::display() const {
    std::cout << year << '-';
    if (month < 10) {
        std::cout << '0';
    }
    std::cout << month << '-';
    if (day < 10) {
        std::cout << '0';
    }
    std::cout << day << '\n';
}

int Date::calWeekday() const {
    int y = year;
    int m = month;
    if (m == 1 || m == 2) {
        --y;
        m += 12;
    }

    int weekday = (day + 2 * m + 3 * (m + 1) / 5 + y
                   + y / 4 - y / 100 + y / 400 + 1) % 7;
    if (weekday < 0) {
        weekday += 7;
    }
    return weekday;
}

bool Date::isLeapYear() const {
    return isLeapYearValue(year);
}

void Date::nextDay() {
    if (day < daysInMonth(year, month)) {
        ++day;
        return;
    }

    day = 1;
    if (month < 12) {
        ++month;
    } else {
        month = 1;
        ++year;
    }
}

bool Date::isLeapYearValue(int y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int Date::daysInMonth(int y, int m) {
    static const int DAYS[] = {
        0, 31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (m == 2 && isLeapYearValue(y)) {
        return 29;
    }
    return DAYS[m];
}

bool Date::isValidDate(int y, int m, int d) {
    if (y < 1 || m < 1 || m > 12 || d < 1) {
        return false;
    }
    return d <= daysInMonth(y, m);
}

void Date::resetToDefault() {
    year = 1900;
    month = 1;
    day = 1;
}
