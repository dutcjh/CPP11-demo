// ������� n ������������ n ���������еĺ͡���Сֵ�����ֵ
#include <iostream>
using namespace std;

int main()
{
    unsigned total_num = 0, i = 0;
    int num = 0, Max = 0, Min = 0, sum = 0;
    cout << "Please input the number of integer(n<=100): ";
    while(cin >> total_num) // ������
    {
        if ((total_num > 100)||(total_num == 0))
            cout << "Error input!!!" << endl;
        else
            break;
        cout << "Please input the number of integer(n<=100): ";
    }
    // ��ʼ��
    cout << "Please input " << total_num << " integers" << endl;
    cin >> num;
    sum += num;
    Max = num;
    Min = num;
    ++i;
    while(i < total_num)
    {
        cin >> num;
        sum += num;
        Max = num > Max? num : Max;
        Min = num < Min? num : Min;
        ++i;
    }
    cout << "-------------------" << endl;
    cout << sum << " " << Min << " " << Max << " " << endl;
    return 0;
}
