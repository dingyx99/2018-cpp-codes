#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
int n;
int main()
{
	cout.setf(ios::left);
	cout.width(8);
	cout<<"a";
	cout.width(8);
	cout<<"a^2";
	cout.width(8);
	cout<<"a^3"<<endl;
	for(int i = 1;i <= 4;i++)
	{
		cout.width(8);
		cout<<i;
		cout.width(8);
		cout<<i*i;
		cout.width(8);
		cout<<i*i*i<<endl;
	}
	return 0;
} 
