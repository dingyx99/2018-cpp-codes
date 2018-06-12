# Description

利用虚函数实现多态: </br>

1. 设计Person类, 要求具有用于表示姓名的保护数据成员: string szName;  实现信息打印的公有成员函数: `void Print()`.其中, Print函数设计为虚函数, 输出的信息格式为: "Person 姓名".</br>
2. 从Person类派生Student类, 添加用于表示学号的保护数据成员: `int iNumber`; 重定义用于信息打印的公有成员函数: `void Print()`.其中, Print函数输出的信息格式为: "Student 姓名 学号".</br>
3. 从 Person类派生Teacher类, 添加用于表示教龄的保护数据成员: `int iYear`; 重定义用于信息打印的公有成员函数: `void Print()`.其中, Print函数输出的信息格式为: "Teacher 姓名 教龄".</br>
4. 从Student类派生Graduate类, 添加用于表示研究方向的保护数据成员: `string szResearch`; 重定义用于信息打印的公有成员函数: `void Print()`.其中, Print函数输出的信息格式为: "Graduate 姓名 研究方向".</br>

在main函数中根据用输入的整数动态创建一个Person类的对象指针数组.用户依次输入对象信息(对象类别及其相应的数据成员值), 根据对象类别动态创建相应的对象并赋给相应的对象指针数组元素.全部录入后, 根据用户输入要显示的对象信息在数组中的位置, 调用Print函数在屏幕上打印出相应对象的信息.如果用户输入`exit`, 则退出.</br>

# Input

对象指针数组的长度; </br>
对象类型及对象信息(输入方式见输入样例); </br>
要显示的对象在数组中的位置; </br>
exit

# Output

用户要求显示的对象信息.

# Sample Input

    4
    Person Zhang
    Student Zhao 200905
    Graduate Li 200905 DataMining
    Teacher Luo 10
    0
    2
    exit

# Sample Output

    Person Zhang
    Graduate Li 200905 DataMining

# Hint