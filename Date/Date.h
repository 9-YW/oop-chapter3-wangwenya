#ifndef DATE_H
#define DATE_H

class Date {
public:
    Date(int y = 1900, int m = 1, int d = 1);

    void Init(int y, int m, int d);

    int getYear() const;
    int getMonth() const;
    int getDay() const;

    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);

    void display() const;
    int calWeekday() const;

    bool isLeapYear() const;
    void nextDay();

private:
    static bool isLeapYearValue(int y);
    static int daysInMonth(int y, int m);
    static bool isValidDate(int y, int m, int d);
    void resetToDefault();

    int year;
    int month;
    int day;
};

#endif
