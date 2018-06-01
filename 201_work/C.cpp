#include <iostream>
#include <cmath>
using namespace std;
float distance(float x1, float y1, float z1, float x2 = 0, float y2 = 0, float z2 = 0)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
}
int main()
{
    float x1 = 0;
    float x2 = 0;
    float y1 = 0;
    float y2 = 0;
    float z1 = 0;
    float z2 = 0;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    cout << distance(x1, y1, z1) << endl;
    cout << distance(x1, y1, z1, x2, y2, z2) << endl;
    return 0;
}