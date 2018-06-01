#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
 
using namespace std;
 
class Rational
{
  public:
    Rational(int up = 0, int down = 1);
 
    Rational Invert() const;
 
    Rational operator-() const;
 
    Rational &operator=(const Rational &r);
 
    Rational &operator++();
 
    Rational operator++(int);
 
    Rational &operator--();
 
    Rational operator--(int);
 
    friend Rational operator+(const Rational &l, const Rational &r);
 
    friend Rational operator-(const Rational &l, const Rational &r);
 
    friend Rational operator*(const Rational &l, const Rational &r);
 
    friend Rational operator/(const Rational &l, const Rational &r);
 
    friend bool operator==(const Rational &l, const Rational &r);
 
    friend bool operator<(const Rational &l, const Rational &r);
 
    friend bool operator>(const Rational &l, const Rational &r);
 
    friend bool operator<=(const Rational &l, const Rational &r);
 
    friend bool operator>=(const Rational &l, const Rational &r);
 
    friend ostream &operator<<(ostream &os, const Rational &rat);
 
    friend istream &operator>>(istream &is, Rational &rat);
 
  private:
    void Simplify();
 
  private:
    int iUp;   
    int iDown; 
};
 
Rational::Rational(int up, int down) : iUp(up), iDown(down)
{
    Simplify();
}
 
void Rational::Simplify()
{
    int m, n, r, s = 1;
 
    if (iUp != 0 && iDown != 0)
    {
        if (iDown < 0)
        {
            s = -s;
            iDown = -iDown;
        }
        if (iUp < 0)
        {
            s = -s;
            iUp = -iUp;
        }
 
        m = iUp;
        n = iDown;
        while (n != 0)
        {
            r = m % n;
            m = n;
            n = r;
        }
 
        if (m != 0)
        {
            iUp = s * iUp / m;
            iDown = iDown / m;
        }
    }
    else
    {
        iUp = 0;
        iDown = 1;
    }
}
 
Rational Rational::Invert() const
{
    return Rational(iDown, iUp);
}
 
Rational Rational::operator-() const
{
    return Rational(-iUp, iDown);
}
 
Rational &Rational::operator=(const Rational &r)
{
    if (this != &r)
    {
        iUp = r.iUp;
        iDown = r.iDown;
    }
 
    return *this;
}
 
Rational &Rational::operator++()
{
    iUp += iDown;
 
    Simplify();
 
    return *this;
}
 
Rational Rational::operator++(int)
{
    Rational t = *this;
    iUp += iDown;
 
    Simplify();
 
    return t;
}
 
Rational &Rational::operator--()
{
    iUp -= iDown;
 
    Simplify();
 
    return *this;
}
 
Rational Rational::operator--(int)
{
    Rational t = *this;
    iUp -= iDown;
 
    Simplify();
 
    return t;
}
 
Rational operator+(const Rational &l, const Rational &r)
{
    int m = l.iUp * r.iDown + l.iDown * r.iUp;
    int n = l.iDown * r.iDown;
 
    Rational t(m, n);
 
    return t;
}
 
Rational operator-(const Rational &l, const Rational &r)
{
    int m = l.iUp * r.iDown - l.iDown * r.iUp;
    int n = l.iDown * r.iDown;
 
    Rational t(m, n);
 
    return t;
}
 
Rational operator*(const Rational &l, const Rational &r)
{
    int m = l.iUp * r.iUp;
    int n = l.iDown * r.iDown;
 
    Rational t(m, n);
 
    return t;
}
 
Rational operator/(const Rational &l, const Rational &r)
{
    int m = l.iUp * r.iDown;
    int n = l.iDown * r.iUp;
 
    Rational t(m, n);
 
    return t;
}
 
bool operator==(const Rational &l, const Rational &r)
{
    return (l.iUp * r.iDown) == (l.iDown * r.iUp);
}
 
bool operator<(const Rational &l, const Rational &r)
{
    return (l.iUp * r.iDown) < (l.iDown * r.iUp);
}
 
bool operator>(const Rational &l, const Rational &r)
{
    return (l.iUp * r.iDown) > (l.iDown * r.iUp);
}
 
bool operator<=(const Rational &l, const Rational &r)
{
    return (l.iUp * r.iDown) <= (l.iDown * r.iUp);
}
 
bool operator>=(const Rational &l, const Rational &r)
{
    return (l.iUp * r.iDown) >= (l.iDown * r.iUp);
}
 
ostream &operator<<(ostream &os, const Rational &rat)
{
    if (rat.iDown == 1)
        os << rat.iUp;
    else
        os << rat.iUp << "/" << rat.iDown;
 
    return os;
}
 
istream &operator>>(istream &is, Rational &rat)
{
    is >> rat.iUp >> rat.iDown;
 
    return is;
}
 
int main()
{
    Rational a, b;
 
    cin >> a;
 
 
    cin >> b;
 
    Rational s = a + b;
    Rational d = a - b;
    Rational p = a * b;
    Rational q = a / b;
 
    cout << "a+b: " << s << endl;
    cout << "a-b: " << d << endl;
    cout << "a*b: " << p << endl;
    cout << "a/b: " << q << endl;
 
    Rational nga = -a;  
    Rational ppa = ++a; 
    Rational rra = --a; 
    Rational app = a++; 
    Rational arr = a--; 
 
    cout << "-a: " << nga << endl;
    cout << "++a: " << ppa << endl;
    cout << "--a: " << rra << endl;
    cout << "a++: " << app << endl;
    cout << "a--: " << arr << endl;
 
    cout << "a<b: " << boolalpha << (a < b) << endl;
    cout << "a<=b: " << boolalpha << (a <= b) << endl;
    cout << "a>b: " << boolalpha << (a > b) << endl;
    cout << "a>=b: " << boolalpha << (a >= b) << endl;
 
    return 0;
}