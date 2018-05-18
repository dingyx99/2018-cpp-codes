#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

class BaseException {
    string message;
public:
    BaseException(string message) {
        this->message = message;
    }

    BaseException(const char *message) {
        this->message = string(message);
    }
};

class Date {
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, month, day;

    bool is_leap(int year) {
        if (year % 4 != 0)
            return false;
        if (year % 400 == 0)
            return true;
        if (year % 100 == 0)
            return false;
        return true;
    }

public:
    Date(int _year, int _month, int _day) {
        if (is_leap(_year)) month_days[1] = 29;
        if (_month < 1 || _month > 12)
            throw BaseException("Illegal Month");
        if (_day < 1 || _day > month_days[_month - 1])
            throw BaseException("Illegal Day");
        year = _year;
        month = _month;
        day = _day;
    }

    int getYear() const {
        return year;
    }

    int getMonth() const {
        return month;
    }

    int getDay() const {
        return day;
    }

    std::string getString() const {
        stringstream ss;
        ss << setfill('0') << setw(4) << year << "-" << setw(2) << month << "-" << day;
        return ss.str();
    }

    Date nextDay() const {
        Date d2 = *this;
        d2.day++;
        if (d2.day > month_days[d2.month - 1]) {
            d2.day -= month_days[d2.month - 1];
            d2.month++;
        }
        if (d2.month > 12) {
            d2.year++;
            d2.month -= 12;
        }
        return d2;
    }

    static int difference(const Date a, const Date b) {
        if (a == b) return 0;
        if (a > b) return -difference(b, a);
        Date a2 = a;
        int d = 0;
        while (a2 < b) {
            a2 = a2.nextDay();
            d++;
        }
        return -d;
    }

    bool operator<(const Date b) const {
        if (this->year < b.year) return true;
        if (this->year > b.year) return false;
        if (this->month < b.month) return true;
        if (this->month > b.month) return false;
        if (this->day < b.day) return true;
        return false;
    }

    bool operator==(const Date b) const {
        return ((this->year == b.year) && (this->month == b.month) && (this->day == b.day));
    }

    bool operator>(const Date b) const {
        return !(*this < b || *this == b);
    }

    bool operator<=(const Date b) const {
        return (*this < b) || (*this == b);
    }

    bool operator>=(const Date b) const {
        return (*this > b) || (*this == b);
    }

    bool operator!=(const Date b) const {
        return !(*this == b);
    }
};

ostream& operator<<(ostream& os, Date const & v) {
    os << v.getString();
    return os;
}
