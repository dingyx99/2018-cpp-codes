#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;
const double PI = 3.1415927;

/*class CPoint
{
    private:
        double x,y;
    public:
        CPoint(double _x = 0,double _y = 0):x(_x),y(_y)
        {}

        CPoint(const CPoint &des):x(des.x),y(des.y)
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
};*/

class Circle
{
    private:
        double x,y;
        double r;
    public:
        Circle(double _x = 0,double _y = 0,double _r = 0):x(_x),y(_y),r(_r)
        {}

        double getArea()
        {
            return PI * r * r;
        }

        double getLength()
        {
            return 2 * PI * r;
        }

        double moveCircle(double _x,double _y)
        {
            x = _x;
            y = _y;
        }

        double zoomCircle(double figure)
        {
            r *= figure;
        }

        double getR()
        {
            return r;
        }

        double getX()
        {
            return x;
        }

        double getY()
        {
            return y;
        }

        double modifyR(double _r)
        {
            r = _r;
        }
};

int main()
{
    Circle cir1(0,0,5);
    
    cout << cir1.getArea() << endl;
    cout << cir1.getLength() << endl;
    cout << cir1.getR() << endl;
    cout << endl;

    cir1.moveCircle(5,5);
    cout << cir1.getX() << "," << cir1.getY() << endl;
    cout << endl;

    cir1.zoomCircle(1.25);
    cout << cir1.getR() << endl;
    cout << cir1.getArea() << endl;
    cout << cir1.getLength() << endl;
    cout << endl;

    cir1.zoomCircle(0.75);
    cout << cir1.getR() << endl;
    cout << cir1.getArea() << endl;
    cout << cir1.getLength() << endl;
    cout <<endl;

    return 0;
}