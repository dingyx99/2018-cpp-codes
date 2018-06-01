#include <iostream>
using namespace std;
void Math(float a,float b,float &sum,float &sub,float &pro);
 
int main()
{
    float sum = 0;
    float sub = 0;
    float pro = 0;
    float a = 0;
    float b = 0;
    cin >> a >> b;
    Math(a, b, sum, sub, pro);
    cout << sum << " " << sub << " " << pro << endl;
    return 0;
}
 
void Math(float a, float b, float &sum, float &sub, float &pro)
{
    sum = a + b;
    sub = a - b;
    pro = a * b;
}