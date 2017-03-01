//输入一个0～6的整数，转换成星期输出。
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    const vector<string> week{"Sunday", "Monday", "Tuesday",\
                "Wednesday","Thursday","Friday","Saturday" };
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
    cout << week[num] << endl;
    return 0;
}
