//Copyright:FANS Corporation
//Auther: Kiana~
//Date: 09-28-2019 10:48AM
//Description: 学生信息系统
//Version: Alpha 0.000000000001

#include <iomanip> //setfill功能
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 20;

class Student
{
    static double sum_sum_max;  //储存最大成绩和最大平均成绩
    static double sum_aver;

public:
    Student()
    {
        Set_stu_inf();
    }

    double Sum()
    {
        double sum = Math + English + Computer;
        return sum;
    }

    double Average()
    {
        double Aver = (Math + English + Computer) / 3;
        return Aver;
    }

    void Print()
    {
        int sum = Sum();
        cout << endl;
        cout << "注册号：" << setfill('0') << setw(5) << No << endl;
        cout << "姓名：" << Name << endl;
        cout << "数学成绩：" << Math << endl;
        cout << "英语成绩：" << English << endl;
        cout << "计算机成绩：" << Computer << endl;
        cout << "总成绩：" << sum << endl;
        cout << "平均成绩" << Average() << endl;
        if (sum >= sum_sum_max)
        {
            sum_sum_max = sum;
        }
        sum_aver = sum_aver + Average();
    }

    void Print_sum_aver()
    {
        cout << "全班学生总成绩最高分为：" << sum_sum_max << endl;
        cout << "全班学生总平均分为：" << sum_aver / SIZE << endl;
    }

    int Get_reg_num()
    {
        return No;
    }

    void Set_stu_inf(int No_temp = 0, string Name_temp = "AAA", double Math_temp = 60, double English_temp = 60, double Computer_temp = 60)
    {
        No = No_temp;
        Name = Name_temp;
        Math = Math_temp;
        English = English_temp;
        Computer = Computer_temp;
    }

    inline void Set_stu_inf_one(int No_temp = 0)
    {
        No = No_temp;
    }
    inline void Set_stu_inf_one(string Name_temp = "AAA")
    {
        Name = Name_temp;
    }
    inline void Set_stu_inf_math(double Math_temp = 60)
    {
        Math = Math_temp;
    }
    inline void Set_stu_inf_english(double English_temp = 60)
    {
        English = English_temp;
    }
    inline void Set_stu_inf_computer(double Computer_temp = 60)
    {
        Computer = Computer_temp;
    }

private:
    int No;
    string Name;
    double Math;
    double English;
    double Computer;
};
double Student::sum_sum_max = 0;
double Student::sum_aver = 0;

int main()
{
    Student stu[SIZE];

    int Menunum1 = 0;
    while (Menunum1 != 6)
    {
        cout << endl;
        cout << "1. 显示当前数据" << endl;
        cout << "2. 设置学生数据" << endl;
        cout << "3. (Debug)创建20个学生数据" << endl;
        cout << "6. 退出" << endl;

        cin >> Menunum1;
        switch (Menunum1)
        {
        case 1:
        {
            for (int i = 0; i < SIZE; i++)
            {
                stu[i].Print();
            }
            stu[SIZE - 1].Print_sum_aver();
            break;
        }
        case 2:
        {
            int Menunum2 = 0;
            int Menunum3 = 0;

            cout << "请输入要设置的数据: ";
            cin >> Menunum2;
            if (Menunum2 <= SIZE)
            {
                stu[Menunum2].Print();
            }

            cout << "请选择你想修改的一项：" << endl;
            cout << "1. 注册号" << endl;
            cout << "2. 姓名" << endl;
            cout << "3. 数学成绩" << endl;
            cout << "4. 英语成绩" << endl;
            cout << "5. 计算机成绩" << endl;

            cin >> Menunum3;
            switch (Menunum3)
            {
            case 1:
            {
                cout << "请输入修改内容：";
                int No_temp = 0;
                cin >> No_temp;
                stu[Menunum2].Set_stu_inf_one(No_temp);
                break;
            }
            case 2:
            {
                cout << "请输入修改内容：";
                string Name_temp = " ";
                cin >> Name_temp;
                stu[Menunum2].Set_stu_inf_one(Name_temp);
                break;
            }
            case 3:
            {
                cout << "请输入修改内容：";
                int Math_temp = 0;
                cin >> Math_temp;
                stu[Menunum2].Set_stu_inf_math(Math_temp);
                break;
            }
            case 4:
            {
                cout << "请输入修改内容：";
                int English_temp = 0;
                cin >> English_temp;
                stu[Menunum2].Set_stu_inf_english(English_temp);
                break;
            }
            case 5:
            {
                cout << "请输入修改内容：";
                int Computer_temp = 0;
                cin >> Computer_temp;
                stu[Menunum2].Set_stu_inf_computer(Computer_temp);
                break;
            }
            default:
                cout << "??????";
                break;
            }
            break;
        }
        case 3: //Debug自动生成20个数据
        {
            stu[0].Set_stu_inf(1, "ABC", 62, 57, 95);
            stu[1].Set_stu_inf(2, "AAA", 30, 30, 0);
            stu[2].Set_stu_inf(3, "DAD", 65, 87, 71);
            stu[3].Set_stu_inf(4, "BBB", 90, 90, 90);
            stu[4].Set_stu_inf(5, "DDD", 88, 68, 91);
            stu[5].Set_stu_inf(6, "CCC", 99, 99, 99);
            stu[6].Set_stu_inf(7, "666", 66, 66, 66);
            stu[7].Set_stu_inf(8, "GKD", 80, 80, 80);
            stu[8].Set_stu_inf(9, "WDNMD", 100, 100, 100);
            stu[9].Set_stu_inf(10, "NBA", 75, 87, 81);
            stu[10].Set_stu_inf(11, "ABB", 12, 23, 34);
            stu[11].Set_stu_inf(12, "BBC", 0, 1, 90);
            stu[12].Set_stu_inf(13, "QWAAEAR", 90, 93, 94);
            stu[13].Set_stu_inf(14, "133233", 87, 83, 74);
            stu[14].Set_stu_inf(15, "QAQ", 61, 60, 64);
            stu[15].Set_stu_inf(16, "OOO", 10, 0, 10);
            stu[16].Set_stu_inf(17, "000", 0, 10, 0);
            stu[17].Set_stu_inf(18, "III", 61, 71, 81);
            stu[18].Set_stu_inf(19, "lll", 81, 71, 61);
            stu[19].Set_stu_inf(20, "GK", 80, 83, 74);
            cout << "生成了20个数据" << endl;
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
