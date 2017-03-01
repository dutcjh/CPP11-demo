// 进制转换。已知一个只包含 0 和 1 的二进制数，
// 长度不大于 10 ，将其转换为十进制并输出。
#include <iostream>
using namespace std;

int main()
{
    unsigned bin = 0, temp = 0, dec = 0, i = 0;
    cout << "Please input a binary number(length <= 10): " << endl;
    cin >> bin;
    while(bin)
    {
        temp = bin % 10;
        if(temp <= 1)
            dec += (temp << i++);
        else // 非法输入
        {
            cout << "Error input!!!" << endl;
            return -1;
        }
        bin /= 10;
    }
    cout << dec << endl;
    return 0;
}
