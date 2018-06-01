#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iomanip>
 
using namespace std;
 
double getEarning(double salary, int absenceDays); 
double getEarning(double baseSalary, double salesSum, double rate); 
double getEarning(int workPieces, double wagePerPiece); 
double getEarning(double hours, double wagePerHour); 
 
int sel,absent,pieces;
double salary,rate,sales,per,hours;
 
int main()
{
    cout << "Please select..." << endl;
    cout << "1: Manager." << endl;
    cout << "2: Sales Man." << endl;
    cout << "3: Pieces Worker." << endl;
    cout << "4: Hour-Worker." << endl;
    cout << "Others: Quit" << endl; 
 
    cin >> sel; 
 
    switch(sel)
    {
    case 1:
        cin >> salary >> absent;
        cout << getEarning(salary,absent);
        break;
    case 2:
        cin >> salary >> sales >> rate;
        cout << getEarning(salary,sales,rate);
        break;
    case 3:
        cin >> pieces >> per;
        cout << getEarning(pieces,per);
        break;
    case 4:
        cin >> hours >> salary;
        cout << getEarning(hours,salary);
        break;
    default:
        break;
    }
 
    return 0;
} 
 
double getEarning(double salary, int absenceDays)
{
    return salary - absenceDays * salary / 22;
}
 
double getEarning(double baseSalary, double salesSum, double rate)
{
    return baseSalary + salesSum * rate;
}
 
double getEarning(int workPieces, double wagePerPiece)
{
    return workPieces * wagePerPiece;
}
 
double getEarning(double hours, double wagePerHour)
{
    return hours * wagePerHour;
}