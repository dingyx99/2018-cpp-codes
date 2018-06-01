#include <iostream>
using namespace std;

class Y
{
    public:
        Y() {cout << "Y"; }
        Y(const Y& _y){cout << "y"; }
};

class X
{
    protected:
        Y b;
    public:
        X(Y _b):b(_b) {cout << "X"; }
};

class Z:public X
{
    protected:
        Y y;
    public:
        z(Y _y):X(_x),y(_y) {cout << "Z"; }
};

int main()
{
    Y y;
    new Z(y);
}