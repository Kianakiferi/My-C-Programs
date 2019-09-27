#include <iomanip> //setfill功能
#include <iostream>
#include <string>
using namespace std;
const int SIZE = 10;

class Student
{
public:
    double sum_sum = 0, sum_aver = 0;
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
        cout << endl;
        cout << "注册号：" << setfill('0') << setw(5) << No << endl;
        cout << "姓名：" << Name << endl;
        cout << "数学成绩：" << Math << endl;
        cout << "英语成绩：" << English << endl;
        cout << "计算机成绩：" << Computer << endl;
        cout << "总成绩：" << Sum() << endl;
        cout << "平均成绩" << Average() << endl;
        sum_sum = sum_sum + Sum();
        sum_aver = sum_aver + Average();
    }

    void Print_sum_aver()
    {
        cout << "全班学生总成绩最高分为：" << endl;
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

private:
    int No;
    string Name;
    double Math;
    double English;
    double Computer;
};

int main()
{
    Student stu[] return 0;
}
