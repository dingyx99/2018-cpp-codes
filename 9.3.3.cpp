#include <iostream>
using namespace std;

class Base
{
    public:
    void method(int i)
    {
        cout << "Value is:" << i << endl;
    }
};

class Sub:public Base
{
    public:
    void method(int j)
    {
        cout << "This value is:" << j << endl;
    }
    void method(char* s)
    {
        cout << "This string is:" << s << endl;
    }
};

int main()
{
    Base* b1 = new Base();
    Base* b2 = new Sub();

    b1 -> method(5);
    b2 -> method(6);

    return 0;
}