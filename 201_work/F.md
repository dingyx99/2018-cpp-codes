# Description

1. 定义人员类Person:
公有成员:姓名`Name`:
保护成员:性别`Gender`, 年龄`Age`: 
构造函数和析构函数.</br>
2. 从人员类Person派生学生记录类StudentRecord:
添加公有成员:学号`Number`, 班级`ClassName`, 
添加静态公有成员:学生总人数`TotalCount`:
添加保护成员:平均成绩`Score`:
实现构造函数和析构函数.</br>
3. 从人员类Person派生教师记录类TeacherRecord:
添加公有成员:学院`CollegeName`, 系`DepartmentName`:
添加保护成员:教龄`Year`:
实现构造函数和析构函数.</br>
4. 从学生记录类StudentRecord和教师记录类TeacherRecord派生学生助教类TeachingAssistant:
添加公有成员:辅导课程`LectureName`:
实现公有函数:显示人员信息`Show`, 屏幕打印 姓名, 性别, 年龄, 学号, 班级, 学生总人数, 平均成绩, 学院, 系, 教龄, 辅导课程.
实现构造函数和析构函数.为检验类间结构设计是否正确, 设计函数void SetName(String name)实现更改一名助教的姓名的功能.</br>
5. 创建一个助教类的对象
<table align="center">
    <tr>
        <th aligh="center">姓名</th>
        <th aligh="center">性别</th>
        <th aligh="center">年龄</th>
        <th aligh="center">学号</th>
        <th aligh="center">班级</th>
        <th aligh="center">平均成绩</th>
        <th aligh="center">学院</th>
        <th aligh="center">系</th>
        <th aligh="center">教龄</th>
        <th aligh="center">辅导课程</th>
    </tr>
    <tr>
        <td align="center">郑七</td>
        <td align="center">男</td>
        <td align="center">22</td>
        <td align="center">2010123</td>
        <td align="center">软20101</td>
        <td align="center">89</td>
        <td align="center">信息</td>
        <td align="center">软件</td>
        <td align="center">1</td>
        <td align="center">数据结构</td>
    </tr>
</table>

显示其信息.</br>
调用更改姓名的函数, 更改其姓名为“郑八”, 并再次显示其信息.</br>

# Input
无</br>

# Output

显示构造的信息和更改前和更改后的助教信息.

# Sample Input

    

# Sample Output

    Person郑七constructed
    Student郑七constructed
    teacher郑七constructed
    teachingassistant郑七constructed
    Name:郑七 Gender:男 Age:22 Number:2010123 ClassName:软20101 TotalCount:1 Score:8
    9 CollegeName:信息 DepartmentName:软件 Year:1 LectureName:数据结构
    Name:郑八 Gender:男 Age:22 Number:2010123 ClassName:软20101 TotalCount:1 Score:8
    9 CollegeName:信息 DepartmentName:软件 Year:1 LectureName:数据结构
    teachingassistant郑八destructed
    teacher郑八destructed
    Student郑八destructed
    Person郑八destructed

# Hint

各类的构造函数和析构函数都有输出. </br>
调用公有函数`Show`,以分别显示各个记录的人员信息. </br>
在派生助教类时, 使用虚基类. </br>