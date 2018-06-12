# Description

设计单链表类,并基于单链表类实现栈类和队列类: 
1. 设计学生信息类StudentRecord,要求包含公有数据成员: `string stuName`和`int stuNo`,设计用于输出学生信息的公有成员函数: `void print`,输出格式为: `Name: stuName, Number: stuNo`.</br>
2. 设计学生链表的结点类StudentNode,要求包含公有数据成员: `StudentRecord data`和`StudentNode *next`.</br>
3. 设计学生链表类LinkedList,要求定义头插入、头删除、尾插入、遍历等公有成员函数</br>
4. 由LinkedList派生LinkedStack类,基于单链表类的功能实现压栈和出栈的成员函数: `void Push(StudentRecord record)和bool Pop(StudentRecord &record)`.</br>
5. 由LinkedList派生LinkedQueue类,基于单链表类的功能实现入队和出队的成员函数: `void EnQueue(StudentRecord record)和bool DeQueue(StudentRecord &record)`.

在main函数中: </br>
定义一个LinkedQueue类的对象queue和一个LinkedStack类的对象stack,并根据用户的输入分别对queue和stack作出相应的操作.若为"Push",则压栈；若为"EnQueue",则入队；若为"Pop",则出栈；若为"DeQueue",则出队；若为"Exit",则退出；若为其它,则给出提示信息"Input error!".入栈和入队时,输入学生姓名和学号.出栈和出队时,若非空,则输出被删除的学生信息；若栈空,则输出Stack is empty!"；若队空,则输出"Queue is empty!".

# Input

操作名；学生姓名,学号.</br>

# Output

删除的信息；提示信息.

# Sample Input

    Push
    ZhangSan 200905
    Push
    LiSi 200906
    EnQueue
    WangWu 200907
    Pop
    exit
    Exit

# Sample Output

    Name: LiSi, Number: 200906
    Input error!

# Hint