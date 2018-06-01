#include <iostream>
using namespace std;
 
class Cylinder
{
  private:
    double height;
    double radius;
    static const double pi;
  public:
    Cylinder(double h, double r) : height(h), radius(r)
    {}
    double Volume()
    {
        return pi * radius * radius * height;
    }
    double Area()
    {
        return 2.0 * pi * radius * (radius + height);
    }
    static double GetPI()
    {
        return pi;
    }
    double GetHeight()
    {
        return height;
    }
    double GetRadius()
    {
        return radius;
    }
    void SetHeight(double h)
    {
        height = h;
    }
    void SetRadius(double r)
    {
        radius = r;
    }

};
 
const double Cylinder::pi = 3.1415926;
 
int main()
{
    double h, r;
    cin >> h >> r;
    Cylinder cl(h, r);
    cout << "pi=" << Cylinder::GetPI() << ", height=" << cl.GetHeight() << ", radius=" << cl.GetRadius() << ":";
    cout << "volume=" << cl.Volume() << ", area=" << cl.Area() << endl;

    return 0;
}