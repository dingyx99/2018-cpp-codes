#include <iostream>
using namespace std;

class T 
{
    public:
        int r,s;
        T(int x,int y) { r = x; s = y;}
};

Class S :public T 
{
    public:
        int t;
        S(int x,int y,int z) {T(x,y); t = z;}
};
