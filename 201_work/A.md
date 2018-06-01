# Description
设计一菜单程序，利用函数重载实现员工月工资的计算，计算方法如下：</br>
（1）管理人员的月工资 ＝ 月薪 － 缺勤天数× 月薪÷ 22；</br>
（2）销售人员的月工资 ＝ 底薪 + 销售金额 × 提成比例；</br>
（3）计件工人的月工资 ＝ 产品件数× 每件报酬；</br>
（4）计时工人的月工资 ＝ 工作小时 × 小时报酬；

# Input

职工类别及相关信息。</br>
职工类别：1表示管理人员；2表示销售人员；3表示计件工人；4表示计时工人；其余字符表示退出。</br>
相关信息：若为管理人员，则输入月薪和缺勤天数；若为销售人员，则输入底薪、销售金额和提成比例；若为计件工人，则输入产品件数和每件报酬；若为计时工人，则输入工作小时和小时报酬。

# Output
员工月工资。

# Sample Input
    1
    5000.0 1

# Sample Output
    Please select...
    1: Manager.
    2: Sales Man.
    3: Pieces Worker.
    4: Hour-Worker.
    Others: Quit
    4772.73

# Hint

    double getEarning(double salary, int absenceDays);
    double getEarning(double baseSalary, double salesSum, double rate); 
    double getEarning(int workPieces, double wagePerPiece);
    double getEarning(double hours, double wagePerHour);
    int main()
    {
        ... 
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
                cin >> ...;
                cout << getEarning(...);
                break;
            case 2:
                cin >> ...;
                cout << getEarning(...);
                break;
            case 3:
                cin >> ...;
                cout << getEarning(...);
                break;
            case 4:
                cin >> ...;
                cout << getEarning(...);
                break;
            default:
                break;
        }
    return 0;
    } 