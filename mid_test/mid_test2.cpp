#include<iostream>
using namespace std;

int chg_money(const int cents);

int main()
{
    int cents = 0;
    cout << "Enter the number of cents: ";
    cin >> cents;
    if (cents < 0 || cents > 99)
    {
        cout << "the money is invalid!" << endl;
        return -1;
    }
    cout << chg_money(cents) << endl;
    return 0;
}

int chg_money(const int cents)
{
    if (cents == 0) //�������
        return 0;
    int i,j,k, counts = 0;
    for (i = cents/25; i >=0; i--) // 25��������
    {
        int last25 = cents - i*25; //ʣ�µ�������
        for (j = last25/10; j >= 0; j--) // 10���ֵ�����
        {
            int last10 = last25 - j*10; //ʣ�µ�������
            for(k = last10/5; k >= 0; k--) // 5���ֵ�����
                counts++; // ����
        }
    }
    return counts;
}
