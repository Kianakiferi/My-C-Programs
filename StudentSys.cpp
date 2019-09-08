//Copyright:FANS Corporation
//Auther: Kiana
//Create Time: 2019-09/06 8:48PM
//Description: 简单的学生信息系统

#include <iomanip> //setfill功能
#include <iostream>
#include <string>
#define SIZE 10
using namespace std;

class Student_List //学生数据类
{
public:
    friend class Func;
    int ID;
    string Name;
    string Class;
    double Grade1;
    double Grade2;
    double Grade3;

    void All_Set(int ID_temp, string Name_temp, string Class_temp, double Grade1_temp, double Grade2_temp, double Grade3_temp) //Debug set
    {
        ID = ID_temp;
        Name = Name_temp;
        Class = Class_temp;
        Grade1 = Grade1_temp;
        Grade2 = Grade2_temp;
        Grade3 = Grade3_temp;
    }
};

class Func
{
public:
    int List_Num; //记录有几组数据

    void Print_one_node(Student_List *p, int flag2) //Flag2为1 开启显示平均分
    {
        if (List_Num == 0)
        {
            cout << "目前有0个数据,请输入后再试!" << endl;
        }
        cout << "学号：" << setfill('0') << setw(5) << p->ID << endl;
        cout << "姓名：" << p->Name << endl;
        cout << "班级：" << p->Class << endl;
        cout << "成绩1：" << p->Grade1 << endl;
        cout << "成绩2：" << p->Grade2 << endl;
        cout << "成绩3：" << p->Grade3 << endl;
        if (flag2 == 1)
        {
            cout << "平均分：" << Calcu_one_average(p) << endl;
        }
        cout << endl;
    }

    void Print_all_node(Student_List *p)
    {
        if (List_Num == 0)
        {
            cout << "目前有0个数据,请输入后再试!" << endl;
        }
        else
        {
            for (int i = 0; i < List_Num; i++) //打印全部学生数据
            {
                Print_one_node(p, 1);
                p++;
            }
            cout << "共" << List_Num << "组有效数据" << endl;
        }
    }

    float Calcu_one_average(Student_List *p)
    {
        float grade_aver;

        grade_aver = ((p->Grade1) + (p->Grade2) + (p->Grade3)) / 3;
        return grade_aver;
    }

    //float Calcu_all_average() 不知道老师您要的 哪个平均分_(:3 <)_

    void Create_one_node(Student_List *p)
    {
        cout << "请输入数据：" << endl;
        cout << "学号：";
        cin >> p->ID;
        cout << "姓名：" << endl;
        cin >> p->Name;
        cout << "班级：" << endl;
        cin >> p->Class;
        cout << "成绩1：" << endl;
        cin >> p->Grade1;
        cout << "成绩2：" << endl;
        cin >> p->Grade2;
        cout << "成绩3：" << endl;
        cin >> p->Grade3;
        cout << "创建完成" << endl;
        List_Num++;
    }

    void Update_one_node(Student_List *p)
    {
        Print_one_node(p, 0);

        int menuNum2 = 0;
        while (menuNum2 != 7) //扣七返回
        {
            cout << endl;
            cout << "输入序号以选择：" << endl;
            cout << "1. 学号" << endl;
            cout << "2. 姓名" << endl;
            cout << "3. 班级" << endl;
            cout << "4. 成绩1" << endl;
            cout << "5. 成绩2" << endl;
            cout << "6. 成绩3" << endl;
            cout << "7. 返回上一级" << endl;

            cin >> menuNum2;
            switch (menuNum2)
            {
            case 1:
                cout << "学号：" << setfill('0') << setw(5) << p->ID << endl;
                cout << "请输入修改的数据：";
                cin >> p->ID;
                cout << endl
                     << "修改完毕" << endl;
                break;
            case 2:
                cout << "姓名：" << p->Name << endl;
                cout << "请输入修改的数据：";
                cin >> p->Name;
                cout << endl
                     << "修改完毕" << endl;
                break;
            case 3:
                cout << "班级：" << p->Class << endl;
                cout << "请输入修改的数据：";
                cin >> p->Class;
                cout << endl
                     << "修改完毕" << endl;
                break;
            case 4:
                cout << "成绩1：" << p->Grade1 << endl;
                cout << "请输入修改的数据：";
                cin >> p->Grade1;
                cout << endl
                     << "修改完毕" << endl;
                break;
            case 5:
                cout << "成绩2：" << p->Grade2 << endl;
                cout << "请输入修改的数据：";
                cin >> p->Grade2;
                cout << endl
                     << "修改完毕" << endl;
                break;
            case 6:
                cout << "成绩3：" << p->Grade3 << endl;
                cout << "请输入修改的数据：";
                cin >> p->Grade3;
                cout << endl
                     << "修改完毕" << endl;
                break;
            default:
                break;
            }
        }
    }

    void Delete_one_node(Student_List *p, int flag1) //flag1为1 开启显示确认信息
    {
        if (flag1 == 0)
        {
            p->All_Set(0, " ", " ", 0, 0, 0); //不让用NULL...
        }
        else if (flag1 == 1)
        {
            char c1;
            cout << "确认删除这个数据？(Y/N): ";
            cin >> c1;
            while ((c1 == 'Y') || (c1 == 'y'))
            {
                p->All_Set(0, " ", " ", 0, 0, 0);
                List_Num--;
                cout << "删除成功" << endl;
                break;
            }
        }
    }

    void Delete_all_node(Student_List *p)
    {
        char c1;
        cout << "确认删除全部数据？";
        cin >> c1;
        while ((c1 == 'Y') || (c1 == 'y'))
        {
            for (int i = 0; i < SIZE; i++)
            {
                Delete_one_node(p, 0);
                p++;
            }
            List_Num = 0;
            break;
        }
    }
};

int main()
{
    Func Func;
    Func.List_Num = 0;

    Student_List stu[SIZE]; //建立stu对象数组
    Student_List *p = stu;

    int menuNum1 = 0;
    while (menuNum1 != 6) //扣个六退出
    {
        cout << endl;
        cout << "目前有" << Func.List_Num << "个数据，输入序号以选择" << endl;
        cout << "1. 显示当前数据" << endl;
        cout << "2. 创建学生数据" << endl;
        cout << "3. 修改学生数据" << endl;
        cout << "4. (Debug)创建10个学生数据" << endl;
        cout << "5. 未完成的" << endl;
        cout << "6. 退出" << endl;

        cin >> menuNum1;
        switch (menuNum1)
        {
        case 1:
        {
            p = &stu[0];
            Func.Print_all_node(p);
            break;
        }
        case 2:
        {
            if (Func.List_Num > SIZE)
            {
                cout << "数据库已满，无法创建" << endl;
                break;
            }
            else
            {
                p = &stu[0];
                for (int i = 0; i < Func.List_Num - 1; i++)
                {
                    p++;
                }
                Func.Create_one_node(p);
            }
            break;
        }
        case 3:
        {
            if (Func.List_Num > 0)
            {
                int Update_num = 0;
                cout << "目前有" << Func.List_Num << "个数据，请输入需要修改的序号：";
                cin >> Update_num;
                if ((Update_num < 0) || (Update_num > Func.List_Num))
                {
                    cout << "输入的参数有误，请检查" << endl;
                }
                else
                {
                    p = &stu[0];
                    for (int j = 0; j < Update_num - 1; j++)
                    {
                        p++;
                    }
                    Func.Update_one_node(p);
                }
                break;
            }
            else
            {
                break;
            }
        }
        case 4: //Debug 自动创建10组数据
        {
            stu[0].All_Set(1, "AAA", "Class01", 78, 86, 80);
            stu[1].All_Set(2, "AAB", "Class01", 90, 61, 87);
            stu[2].All_Set(3, "AAC", "Class01", 85, 85, 84);
            stu[3].All_Set(4, "AAD", "Class01", 61, 61, 59);
            stu[4].All_Set(5, "AAE", "Class01", 71, 90, 92);
            stu[5].All_Set(6, "AAF", "Class01", 92, 91, 92);
            stu[6].All_Set(7, "AAG", "Class01", 62, 45, 93);
            stu[7].All_Set(8, "AAH", "Class01", 85, 79, 82);
            stu[8].All_Set(9, "AAI", "Class01", 90, 81, 84);
            stu[9].All_Set(10, "AAJ", "Class01", 76, 79, 81);
            Func.List_Num = 10;
            cout << "生成了10个数据" << endl;
        }
        default:
            break;
        }
    }
    return 0;
}