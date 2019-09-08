//Copyright:FANS Corporation
//Auther: Kiana
//Create Time: 2019-09/06 8:48PM
//Description: �򵥵�ѧ����Ϣϵͳ

#include <iomanip> //setfill����
#include <iostream>
#include <string>
#define SIZE 10
using namespace std;

class Student_List //ѧ��������
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
    int List_Num; //��¼�м�������

    void Print_one_node(Student_List *p, int flag2) //Flag2Ϊ1 ������ʾƽ����
    {
        if (List_Num == 0)
        {
            cout << "Ŀǰ��0������,�����������!" << endl;
        }
        cout << "ѧ�ţ�" << setfill('0') << setw(5) << p->ID << endl;
        cout << "������" << p->Name << endl;
        cout << "�༶��" << p->Class << endl;
        cout << "�ɼ�1��" << p->Grade1 << endl;
        cout << "�ɼ�2��" << p->Grade2 << endl;
        cout << "�ɼ�3��" << p->Grade3 << endl;
        if (flag2 == 1)
        {
            cout << "ƽ���֣�" << Calcu_one_average(p) << endl;
        }
        cout << endl;
    }

    void Print_all_node(Student_List *p)
    {
        if (List_Num == 0)
        {
            cout << "Ŀǰ��0������,�����������!" << endl;
        }
        else
        {
            for (int i = 0; i < List_Num; i++) //��ӡȫ��ѧ������
            {
                Print_one_node(p, 1);
                p++;
            }
            cout << "��" << List_Num << "����Ч����" << endl;
        }
    }

    float Calcu_one_average(Student_List *p)
    {
        float grade_aver;

        grade_aver = ((p->Grade1) + (p->Grade2) + (p->Grade3)) / 3;
        return grade_aver;
    }

    //float Calcu_all_average() ��֪����ʦ��Ҫ�� �ĸ�ƽ����_(:3 <)_

    void Create_one_node(Student_List *p)
    {
        cout << "���������ݣ�" << endl;
        cout << "ѧ�ţ�";
        cin >> p->ID;
        cout << "������" << endl;
        cin >> p->Name;
        cout << "�༶��" << endl;
        cin >> p->Class;
        cout << "�ɼ�1��" << endl;
        cin >> p->Grade1;
        cout << "�ɼ�2��" << endl;
        cin >> p->Grade2;
        cout << "�ɼ�3��" << endl;
        cin >> p->Grade3;
        cout << "�������" << endl;
        List_Num++;
    }

    void Update_one_node(Student_List *p)
    {
        Print_one_node(p, 0);

        int menuNum2 = 0;
        while (menuNum2 != 7) //���߷���
        {
            cout << endl;
            cout << "���������ѡ��" << endl;
            cout << "1. ѧ��" << endl;
            cout << "2. ����" << endl;
            cout << "3. �༶" << endl;
            cout << "4. �ɼ�1" << endl;
            cout << "5. �ɼ�2" << endl;
            cout << "6. �ɼ�3" << endl;
            cout << "7. ������һ��" << endl;

            cin >> menuNum2;
            switch (menuNum2)
            {
            case 1:
                cout << "ѧ�ţ�" << setfill('0') << setw(5) << p->ID << endl;
                cout << "�������޸ĵ����ݣ�";
                cin >> p->ID;
                cout << endl
                     << "�޸����" << endl;
                break;
            case 2:
                cout << "������" << p->Name << endl;
                cout << "�������޸ĵ����ݣ�";
                cin >> p->Name;
                cout << endl
                     << "�޸����" << endl;
                break;
            case 3:
                cout << "�༶��" << p->Class << endl;
                cout << "�������޸ĵ����ݣ�";
                cin >> p->Class;
                cout << endl
                     << "�޸����" << endl;
                break;
            case 4:
                cout << "�ɼ�1��" << p->Grade1 << endl;
                cout << "�������޸ĵ����ݣ�";
                cin >> p->Grade1;
                cout << endl
                     << "�޸����" << endl;
                break;
            case 5:
                cout << "�ɼ�2��" << p->Grade2 << endl;
                cout << "�������޸ĵ����ݣ�";
                cin >> p->Grade2;
                cout << endl
                     << "�޸����" << endl;
                break;
            case 6:
                cout << "�ɼ�3��" << p->Grade3 << endl;
                cout << "�������޸ĵ����ݣ�";
                cin >> p->Grade3;
                cout << endl
                     << "�޸����" << endl;
                break;
            default:
                break;
            }
        }
    }

    void Delete_one_node(Student_List *p, int flag1) //flag1Ϊ1 ������ʾȷ����Ϣ
    {
        if (flag1 == 0)
        {
            p->All_Set(0, " ", " ", 0, 0, 0); //������NULL...
        }
        else if (flag1 == 1)
        {
            char c1;
            cout << "ȷ��ɾ��������ݣ�(Y/N): ";
            cin >> c1;
            while ((c1 == 'Y') || (c1 == 'y'))
            {
                p->All_Set(0, " ", " ", 0, 0, 0);
                List_Num--;
                cout << "ɾ���ɹ�" << endl;
                break;
            }
        }
    }

    void Delete_all_node(Student_List *p)
    {
        char c1;
        cout << "ȷ��ɾ��ȫ�����ݣ�";
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

    Student_List stu[SIZE]; //����stu��������
    Student_List *p = stu;

    int menuNum1 = 0;
    while (menuNum1 != 6) //�۸����˳�
    {
        cout << endl;
        cout << "Ŀǰ��" << Func.List_Num << "�����ݣ����������ѡ��" << endl;
        cout << "1. ��ʾ��ǰ����" << endl;
        cout << "2. ����ѧ������" << endl;
        cout << "3. �޸�ѧ������" << endl;
        cout << "4. (Debug)����10��ѧ������" << endl;
        cout << "5. δ��ɵ�" << endl;
        cout << "6. �˳�" << endl;

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
                cout << "���ݿ��������޷�����" << endl;
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
                cout << "Ŀǰ��" << Func.List_Num << "�����ݣ���������Ҫ�޸ĵ���ţ�";
                cin >> Update_num;
                if ((Update_num < 0) || (Update_num > Func.List_Num))
                {
                    cout << "����Ĳ�����������" << endl;
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
        case 4: //Debug �Զ�����10������
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
            cout << "������10������" << endl;
        }
        default:
            break;
        }
    }
    return 0;
}