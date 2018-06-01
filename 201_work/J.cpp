#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
 
class Person
{  
  protected:
    string szName;

  public:
    Person(const string &name);
    virtual void Print() const;
};
 
Person::Person(const string &name) : szName(name)
{}
 
void Person::Print() const
{
    cout << "Person " << szName << endl;
}
 
class Student : public Person
{
  public:
    Student(const string &name, int number);
    void Print() const;
 
  protected:
    int iNumber;
};
 
Student::Student(const string &name, int number) : Person(name), iNumber(number)
{}
 
void Student::Print() const
{
    cout << "Student " << szName << " " << iNumber << endl;
}
 
class Teacher : public Person
{
  public:
    Teacher(const string &name, int year);
    void Print() const;
 
  protected:
    int iYear;
};
 
Teacher::Teacher(const string &name, int year) : Person(name), iYear(year)
{}
 
void Teacher::Print() const
{
    cout << "Teacher " << szName << " " << iYear << endl;
}
 
class Graduate : public Student
{
  public:
    Graduate(const string &name, int number, string major);
    void Print() const;
 
  protected:
    string szResearch;
};
 
Graduate::Graduate(const string &name, int number, string major) : Student(name, number), szResearch(major)
{}
 
void Graduate::Print() const
{
    cout << "Graduate " << szName << " " << iNumber << " " << szResearch << endl;
}
 
int main()
{
    int psNum;
    cin >> psNum;
 
    Person **psArr = new Person *[psNum];
 
    string szType, szName, szMajor;
    int iNumber, iYear;
 
    for (int i = 0; i < psNum; i++)
    {
        cin >> szType;
        if (szType == "Person")
        {
            cin >> szName;
            psArr[i] = new Person(szName);
        }
        else if (szType == "Student")
        {
            cin >> szName >> iNumber;
            psArr[i] = new Student(szName, iNumber);
        }
        else if (szType == "Teacher")
        {
            cin >> szName >> iYear;
            psArr[i] = new Teacher(szName, iYear);
        }
        else if (szType == "Graduate")
        {
            cin >> szName >> iNumber >> szMajor;
            psArr[i] = new Graduate(szName, iNumber, szMajor);
        }
        else
        {}
    }
 
    string szIdx;
    int objIdx;
    cin >> szIdx;
    while (szIdx != "exit")
    {
        objIdx = atoi(szIdx.c_str());
        objIdx = max(0, min(objIdx, psNum));
 
        psArr[objIdx]->Print();
 
        cin >> szIdx;
    }
 
    for (int i = 0; i < psNum; i++)
    {
        if (psArr[i])
            delete psArr[i];
    }
    delete[] psArr;
 
    return 0;
}