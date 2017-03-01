//输入一个0～6的整数，转换成星期输出。
#include <iostream>
using namespace std;

int main()
{
    unsigned num;
    do  // 输入检查
    {
        cout << "Please input a number(0~6): ";
        cin >> num;
        if (num > 6)
            cout << "Error input!" << endl;
        else
            break;
    }while(1);
    switch(num) // 转换
    {
        case 0: cout << "Sunday" << endl; break;
        case 1: cout << "Monday" << endl; break;
        case 2: cout << "Tuesday" << endl; break;
        case 3: cout << "Wednesday" << endl; break;
        case 4: cout << "Thursday" << endl; break;
        case 5: cout << "Friday" << endl; break;
        case 6: cout << "Saturday" << endl; break;
        default:cout << "Error!!!" << endl; break;
    }
    return 0;
}
