//����һ��0��6��������ת�������������
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    const vector<string> week{"Sunday", "Monday", "Tuesday",\
                "Wednesday","Thursday","Friday","Saturday" };
    unsigned num;
    do  // ������
    {
        cout << "Please input a number(0~6): ";
        cin >> num;
        if (num > 6)
            cout << "Error input!" << endl;
        else
            break;
    }while(1);
    cout << week[num] << endl;
    return 0;
}
