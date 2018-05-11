#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <ctime>
using namespace std;
map<int, string> Month={{1,"January"},
                      {2,"February"},
                      {3,"March"},
                      {4,"April"},
                      {5,"May"},
                      {6,"June"},
                      {7,"July"},
                      {8,"August"},
                      {9,"September"},
                      {10,"October"},
                      {11,"November"},
                      {12,"December"}};
int n;
int main()
{
    srand(time(NULL));
    n = rand()%12;
    cout<<Month[n]<<endl;
    return 0;
}