#include <iostream>
#include <cmath>
#include <string>

using namespace std;


class RationalException {
    string __message;
public:
    RationalException(string message) : __message(message) {}

    RationalException(const char *message) : __message(message) {}

    string getMessage() { return string(__message); }
};

template<class T>
class Rational {
    T __numerator, __denominator;

    static T _gcd(T a, T b) {
        if (a == 0 || b == 0)
            return 0;
        if (a == b)
            return a;
        if (a > b)
            return _gcd(a - b, b);
        return _gcd(a, b - a);
    }

    static T _lcm(T a, T b) {
        return (a / _gcd(a, b)) * b;
    }

    void __reduction() {
        if (__numerator == 0) __denominator = 1;
        if (__denominator < 0) {
            __numerator = -__numerator;
            __denominator = -__denominator;
        }
        T g = _gcd(abs(__numerator), __denominator);
        if (g == 0)
            throw RationalException("Divide by 0");
        __numerator /= g;
        __denominator /= g;
    }

    Rational<T> &__shrink(T new_denominator) {
        Rational<T> a(*this);
        T factor = new_denominator / a.__denominator;
        a.__numerator *= factor;
        a.__denominator *= factor;
        return a;
    }

public:
    template<class T2>
    friend ostream &operator<<(ostream &os, const Rational<T2> &r);

    Rational(const T numerator, const T denominator) {
        if (denominator == 0)
            throw RationalException("Divide by 0");
        __numerator = numerator;
        __denominator = denominator;
        __reduction();
    }

    Rational(const Rational<T> &existed_object) {
        __numerator = existed_object.__numerator;
        __denominator = existed_object.__denominator;
        __reduction();
    }

    Rational<T> &operator=(const Rational<T> &b) const {
        Rational<T> a(b);
        return a;
    }

    Rational<T> &operator+(const Rational<T> &b) const {
        Rational<T> a(*this), b2(b);
        T lcm = _lcm(a.__denominator, b.__denominator);
        a = a.__shrink(lcm);
        b2 = b2.__shrink(lcm);
        a.__numerator += b2.__numerator;
        a.__reduction();
        return a;
    }

    Rational<T> &operator-(const Rational<T> &b) const {
        Rational<T> a(*this), b2(b);
        T lcm = _lcm(a.__denominator, b.__denominator);
        a = a.__shrink(lcm);
        b2 = b2.__shrink(lcm);
        a.__numerator -= b2.__numerator;
        a.__reduction();
        return a;
    }

    Rational<T> operator*(const Rational<T> &b) const {
        return Rational<T>(this->__numerator * b.__numerator, this->__denominator*this->__denominator);
    }

    Rational<T> operator/(const Rational<T> &b) const {
        return Rational<T>(this->__numerator * b.__denominator, this->__denominator * b.__numerator);
    }
};

template<class T>
ostream &operator<<(ostream &os, const Rational<T> &r) {
    os << r.__numerator << '/' << r.__denominator;
    return os;
}
