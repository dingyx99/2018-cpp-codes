#include <iostream>
#include <cstring>
using namespace std;
 
class Person
{
  protected:
    string Gender;
    int Age;
 
  public:
    string Name;
    Person(string gender, int age, string name)
    {
        Gender = gender;
        Age = age;
        Name = name;
        cout << "Person" << Name << "constructed" << endl;
    }
    ~Person()
    {
        cout << "Person" << Name << "destructed" << endl;
    }
};
 
class StudentRecord : virtual public Person
{
  protected:
    int Score;
 
  public:
    string Number;
    string ClassName;
    static int TotalCount;
    StudentRecord(string number, string classname, int score, string gender, int age, string name) : Person(gender, age, name)
    {
        Number = number;
        ClassName = classname;
        Score = score;
        ++TotalCount;
        cout << "Student" << Name << "constructed" << endl;
    }
    ~StudentRecord()
    {
        --TotalCount;
        cout << "Student" << Name << "destructed" << endl;
    }
};
 
int StudentRecord::TotalCount = 0;
 
class TeacherRecord : virtual public Person
{
  protected:
    int Year;
 
  public:
    string CollegeName;
    string DepartmentName;
    TeacherRecord(string collegename, string departmentname, int year, string gender, int age, string name) : Person(gender, age, name)
    {
        CollegeName = collegename;
        DepartmentName = departmentname;
        Year = year;
        cout << "teacher" << Name << "constructed" << endl;
    }
    ~TeacherRecord()
    {
        cout << "teacher" << Name << "destructed" << endl;
    }
};
 
class TeachingAssistant : public StudentRecord, public TeacherRecord
{
  public:
    string LectureName;
    TeachingAssistant(string lecturename, string number, string classname, int score, string collegename, string departmentname, int year, string gender, int age, string name) : Person(gender, age, name), StudentRecord(number, classname, score, gender, age, name), TeacherRecord(collegename, departmentname, year, gender, age, name)
    {
        LectureName = lecturename;
        cout << "teachingassistant" << Name << "constructed" << endl;
    }
    ~TeachingAssistant()
    {
        cout << "teachingassistant" << Name << "destructed" << endl;
    }
    void Show()
    {
        cout << "Name:" << Name << " "
             << "Gender:" << Gender << " "
             << "Age:" << Age << " "
             << "Number:" << Number << " "
             << "ClassName:" << ClassName << " "
             << "TotalCount:" << TotalCount << " "
             << "Score:" << Score << " "
             << "CollegeName:" << CollegeName << " "
             << "DepartmentName:" << DepartmentName << " "
             << "Year:" << Year << " "
             << "LectureName:" << LectureName << endl;
    }
    void SetName(string name)
    {
        Name = name;
    }
};
int main()
{
    TeachingAssistant ta("数据结构", "2010123", "软20101", 89, "信息", "软件", 1, "男", 22, "郑七");
    ta.Show();
    ta.SetName("郑八");
    ta.Show();
    return 0;
}