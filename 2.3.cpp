#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;

struct Point{
	int x,y;
}A,B;
double Distance(Point A,Point B)
{
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
int main()
{
	cin>>A.x>>A.y>>B.x>>B.y;
	cout<<fixed<<setprecision(5)<<Distance(A,B)<<endl;
	return 0;
}
