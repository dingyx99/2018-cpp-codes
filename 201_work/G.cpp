#include <iostream>
#include <cmath>
using namespace std;
 
class Point
{
  private:
    double x;
    double y;
  public:
    Point(double _x=0, double _y=0):x(_x),y(_y)
    {}
};
 
class Line
{
  private:
    Point ptStart;
    Point ptEnd;

  public:
    Line(const Point &start, const Point &end):ptStart(start),ptEnd(end)
    {}
    double Length()
    {
        double len;
        len = sqrt((ptEnd.x-ptStart.x)*(ptEnd.x-ptStart.x) + (ptEnd.y-ptStart.y)*(ptEnd.y-ptStart.y));
        return len;
    }
};
 
class Triangle
{
  private:
    Point ptA;
    Point ptB;
    Point ptC;

  public:
    Triangle(const Point &p1, const Point &p2, const Point &p3):ptA(p1),ptB(p2),ptC(p3)
    {}
    double Perimeter();
    double Area();
};
 
double Triangle::Perimeter()
{
    Line lab(ptA,ptB), lbc(ptB,ptC), lca(ptC,ptA);
    return lab.Length()+lbc.Length()+lca.Length();
}
 
double Triangle::Area()
{
     Line lab(ptA,ptB), lbc(ptB,ptC), lca(ptC,ptA);
     double a = lab.Length();
     double b = lbc.Length();
     double c = lca.Length();
     double p = 0.5*(a+b+c);
 
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
 
int main()
{
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
 
    Triangle t(Point(x1,y1),Point(x2,y2),Point(x3,y3));
    cout << t.Perimeter() << " " << t.Area() << endl;
 
    return 0;
}