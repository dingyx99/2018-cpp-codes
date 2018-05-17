#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class Account
{
    private:
        double savings;
        static double annual;
        
    public:
        Account(double _sav):savings(_sav)
        {}

        double calculate()
        {
            return savings * annual / 12;
        }

        static void modify(double nAnnual)
        {
            annual = nAnnual;
            cout<<"Current annual is:"<< nAnnual << endl;
        }
};

double Account::annual = 0;

int main()
{
    Account saver1(2000);
    Account saver2(3000);

    saver1.modify(0.03);
    cout<<"Saver1:"<<saver1.calculate()<<endl<<"Saver2:"<<saver2.calculate()<<endl;

    saver1.modify(0.04);
    cout<<"Saver1:"<<saver1.calculate()<<endl<<"Saver2:"<<saver2.calculate()<<endl;

    return 0;
}
