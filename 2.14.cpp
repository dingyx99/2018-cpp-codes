#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    for(int i = 2;i <= 100;i++)
    {
        for(int j = 1;j*j <= i;j++)
        {
            if(i % j != 0) { cout<<i<<endl;  break; }
            else continue;
        }
    }
    return 0;
}