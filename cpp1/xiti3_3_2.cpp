// ����ת������֪һ��ֻ���� 0 �� 1 �Ķ���������
// ���Ȳ����� 10 ������ת��Ϊʮ���Ʋ������
#include <iostream>
#include <string>
using namespace std;

#define LEN 10   // �Զ�����������ĳ��ȣ����ܴ���32��

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
        else // �Ƿ�����
        {
            cout << "Error input!!!" << endl;
            return -1;
        }
    }
    cout << dec << endl;
    return 0;
}
