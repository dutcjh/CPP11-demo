#include<iostream>
#include<string>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
    string val = "a value"; // ���ǽ����ҵ�ֵ
    list<string> lst = {"about", "after", "and", "a value", "account"};
    auto result = find(lst.cbegin(), lst.cend(), val);
    // ������
    cout << "The value \"" << val
        << (result == lst.cend()? "\" is not present" : "\" is present") << endl;
    return 0;
}
