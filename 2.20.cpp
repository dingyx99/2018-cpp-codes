#include <iostream>
using namespace std;
int m,n;
void prim(int m, int n)
 {
     if (m > n)
     {
         while (m%n) n++;
         m/=n;
         cout << n << ", ";
         prim(m, n);
     }
}

int main()
{
    cin>>m;
    prim(m,2);
    return 0;
}