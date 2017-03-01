// 进制转换。已知一个只包含 0 和 1 的二进制数，
// 长度不大于 10 ，将其转换为十进制并输出。
#include <iostream>
#include <string>
using namespace std;

#define LEN 10   // 自定义二进制数的长度（不能大于32）

int main()
{
    string buff;
    unsigned dec = 0;
    cout << "Please input a binary number(length <= " << LEN << "): " << endl;
    cin >> buff;
    decltype(buff.size()) n = buff.size();
    if (n > LEN)
    {
        cout << "The binary number is too long!" << endl;
        return -1;
    }
    for(auto c : buff)
    {
        if ((c == '0')||(c == '1'))
            dec += ((c - '0') << --n);
        else // 非法输入
        {
            cout << "Error input!!!" << endl;
            return -1;
        }
    }
    cout << dec << endl;
    return 0;
}
