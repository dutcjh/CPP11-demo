#include<iostream>
#include<string>
using namespace std;

void reserve(string &s)
{
    for(size_t i = 0; i < s.length()/2; ++i)
    {
        char t = s[i];
        s[i] = s[s.length()-1-i];
        s[s.length()-1-i] = t;
    }
}

int main()
{
    string s;
    getline(cin, s);//�����ַ�����֧�ֿո�
    reserve(s); // ����
    cout << s << endl; //���
    return 0;
}
