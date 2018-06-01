#include <iostream>
#include <string>
using namespace std;
 
class StudentRecord
{  
  private:
    string stuName;
    int stuNo;

  public:
    StudentRecord(const string &name = "", int number = 0) : stuName(name), stuNo(number)
    {}
    ~StudentRecord()
    {}
    void Print();
};
 
void StudentRecord::Print()
{
    cout << "Name: " << stuName << ", Number: " << stuNo << endl;
}
 
class StudentNode
{
  private:
    StudentRecord data;
    StudentNode *next;

  public:
    StudentNode(const StudentRecord &stu, StudentNode *pNext = NULL) : data(stu),next(pNext)
    {}
    ~StudentNode()
    {}
};
 
class LinkedList
{
  private:
    StudentNode *head;
    StudentNode *tail;

  public:
    LinkedList() : head(0), tail(0)
    {}
    ~LinkedList()
    {
        while (head != 0)
        {
            FrontRemove();
        }
    }
    StudentNode *HeadNode()
    {
        return head;
    }
    StudentNode *TailNode()
    {
        return tail;
    }
    void FrontInsert(const StudentRecord &stu)
    {
        StudentNode *t = new StudentNode(stu);
        t->next = head;
        head = t;
    }
    void FrontRemove()
    {
        if (head != 0)
        {
            StudentNode *t = head;
            head = head->next;
            delete t;
        }
    }
    void BackInsert(const StudentRecord &stu)
    {
        StudentNode *t = new StudentNode(stu);
 
        if (tail != 0)
        {
            tail->next = t;
        }
        else
        {
            head = t;
        }
        tail = t;
    }
    void Print()
    {
        StudentNode *t = head;
        while (t != 0)
        {
            t->data.Print();
        }
    }
};
 
class LinkedStack : public LinkedList
{
  public:
    void Push(StudentRecord record)
    {
        FrontInsert(record);
    }
    bool Pop(StudentRecord &record)
    {
        if (head != 0)
        {
            record = HeadNode()->data;
            FrontRemove();
            return true;
        }
        else
        {
            return false;
        }
    }
};
 
class LinkedQueue : public LinkedList
{
  public:
    void EnQueue(StudentRecord record)
    {
        BackInsert(record);
    }
    bool DeQueue(StudentRecord &record)
    {
        if (head != 0)
        {
            record = HeadNode()->data;
            FrontRemove();
 
            return true;
        }
        else
        {
            return false;
        }
    }
};
 
int main()
{
    LinkedQueue queue;
    LinkedStack stack;
 
    string szOp;
    while (szOp != "Exit")
    {
        cin >> szOp;
        if (szOp == "Push")
        {
            string name;
            int num;
            cin >> name >> num;
            stack.Push(StudentRecord(name, num));
        }
        else if (szOp == "EnQueue")
        {
            string name;
            int num;
            cin >> name >> num;
            queue.EnQueue(StudentRecord(name, num));
        }
        else if (szOp == "Pop")
        {
            StudentRecord stu;
            if (stack.Pop(stu))
            {
                stu.Print();
            }
            else
            {
                cout << "Stack is empty!" << endl;
            }
        }
        else if (szOp == "DeQueue")
        {
            StudentRecord stu;
            if (queue.DeQueue(stu))
            {
                stu.Print();
            }
            else
            {
                cout << "Queue is empty!" << endl;
            }
        }
        else if (szOp == "Exit")
        {
            break;
        }
        else
        {
            cout << "Input error!" << endl;
        }
    }
    return 0;
}