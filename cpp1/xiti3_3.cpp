// ����ת������֪һ��ֻ���� 0 �� 1 �Ķ���������
// ���Ȳ����� 10 ������ת��Ϊʮ���Ʋ������
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
        else // �Ƿ�����
        {
            cout << "Error input!!!" << endl;
            return -1;
        }
        bin /= 10;
    }
    cout << dec << endl;
    return 0;
}
