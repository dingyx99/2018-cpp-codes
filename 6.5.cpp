#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

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

class CPoint
{
    private:
        double x,y;
    public:
        CPoint(double _x = 0,double _y = 0):x(_x),y(_y)
        {}

        double Distance()
        {
            return sqrt(x * x + y * y);
        }

        double anotherDistance(CPoint pnt)
        {
            return sqrt(pow((x - pnt.x),2)+pow((y - pnt.y),2));
        }

        double getX()
        {
            return x;
        }

        double getY()
        {
            return y;
        }

        void modifyX(double _x)
        {
            x = _x;
            cout << "Successfully modified variable X to " << x << endl ;
        }
        void modifyY(double _y)
        {
            y = _y;
            cout << "Successfully modified variable Y to " << y << endl ;
        }
        void modifyPoint(double _x,double _y)
        {
            x = _x;
            y = _y;
            cout << "Successfully modified current point to (" << x << "," << y << ")" << endl ;
        }
};

using namespace std;

int main()
{
    CPoint a(4,5);
    CPoint b(1,1);

    cout << a.Distance() << endl ;
    cout << "Tested function Distance()" << endl << endl ;

    cout << a.anotherDistance(b) << endl ;
    cout << "Tested function anotherDistance()" << endl << endl ;

    cout << "Point a's coordinate is:" << a.getX() << "," << a.getY() << endl ;
    cout << "Tested functions getX() and getY()" << endl << endl ;

    b.modifyX(3);
    b.modifyY(4);
    cout << "Tested functions modifyX() and modifyY()" << endl << endl ;

    a.modifyPoint(8,8);
    cout << "Tested function modifyPoint()" << endl ;

    return 0;
}