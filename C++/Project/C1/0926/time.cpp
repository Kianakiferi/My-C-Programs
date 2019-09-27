//Copyright:FANS Corporation
//Auther: Kiana~
//Date: 09-27-2019 4:29PM
//Description: ʱ����
//Version: Alpha 0.000000000001

#include <ctime>    //��ȡʱ�书��
#include <iomanip>  //setfill����
#include <iostream>
using namespace std;

class Date
{
public:
    Date()
    {
        Set_time();
    }

    ~Date()
    {
        cout << "Boom!" << endl;
    }

    void Set_time(int Hour_t = 0, int Minute_t = 0, int Second_t = 1) //��ȱʡֵ������ʱ�亯��
    {
        Hour = Hour_t;  //Сʱǰû�е�λ�ˣ��Ͳ��ٽ�λ��~

        if (Second_t >= 60)
        {
            int s = Second_t / 60;
            Second = Second_t - 60 * s;
            Minute_t = Minute_t + s;
        }
        else
        {
            Second = Second_t;
        }

        if (Minute_t >= 60)
        {
            int h = Minute_t / 60;
            Minute = Minute_t - 60 * h;
            Hour = Hour + h;
        }
        else
        {
            Minute = Minute_t;
        }
    }

    void Set_now_time() //��ȡ��ǰʱ��
    {
        time_t rawtime;
        struct tm *plocal;

        time(&rawtime);
        plocal = localtime(&rawtime);
        Set_time(plocal->tm_hour, plocal->tm_min, plocal->tm_sec);
    }

    void Print_date()   //���Ϊ00:00:00�ĸ�ʽ
    {
        cout << "Time is: " << setfill('0') << setw(2) << Hour << ":" << setfill('0') << setw(2) << Minute << ":" << setfill('0') << setw(2) << Second << endl;
    }

private:
    int Hour;
    int Minute;
    int Second;
};

int main()
{
    int SIZE = 5;

    //cin >> SIZE;  //��ѡ����

    Date *p1, *phead;
    p1 = new Date[SIZE];
    phead = p1;

    int Menunum1 = 0;
    while (Menunum1 != 6)
    {
        cout << endl;
        cout << "1. ��ʾ��ǰ����" << endl;
        cout << "2. ����ʱ������" << endl;
        cout << "3. (Debug)����5��ʱ������" << endl;
        cout << "6. �˳�" << endl;

        cin >> Menunum1;
        switch (Menunum1)
        {
        case 1:
        {
            p1 = phead;
            for (int i = 0; i < SIZE; i++)
            {
                p1->Print_date();
                p1++;
            }
            break;
        }
        case 2:
        {
            int Menunum2 = 0;
            cout << "��ѡ��Ҫ��������: ";
            cin >> Menunum2;
            p1 = phead;
            for (int i = 0; i < Menunum2; i++)
            {
                p1++;
            }

            int h, m, s;
            cout << "���������ݣ�" << endl;
            cin >> h >> m >> s;
            p1->Set_time(h, m, s); 
            p1++;
            break;
        }
        case 3:
        {
            p1 = phead;
            p1[0].Set_time(); //[0]ȱʡ����
            p1++;

            p1->Set_now_time(); //[1] ����ʱ��
            p1++;

            p1->Set_time(66, 66, 66); //[2]666ʱ��
            p1++;

            p1->Set_time(11, 111, 1111);
            p1++;

            p1->Set_time(1, 2, 3);
            break;
        }
        default:
            break;
        }
    }
    delete[] phead;
    return 0;
}