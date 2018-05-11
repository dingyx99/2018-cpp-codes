#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;
struct bmi
{
    int w,h,Case;
}person;

void Judge(bmi x)
{
    double tmp = x.w / (x.h*x.h);
    cout << tmp << " " << endl;
    if(tmp < 18.5) x.Case = 1;
    else if(tmp >= 18.5 && tmp < 25) x.Case = 2;
    else if(tmp >= 25 && tmp < 30) x.Case = 3;
    else x.Case = 4;
}

int main()
{
    cin>>person.w>>person.h;
    
    Judge(person);
    
    switch (person.Case)
    {
        case 1:
            cout<<"Thin"<<endl;
            break;

        case 2:
            cout<<"Normal"<<endl;
            break;
        
        case 3:
            cout<<"Overweight"<<endl;
            break;
        
        case 4:
            cout<<"Fat"<<endl;
            break;

        default:
            break;
    }
    return 0;
}