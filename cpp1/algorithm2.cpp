#include<iostream>
#include<string>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
    string val = "a value"; // 我们将查找的值
    list<string> lst = {"about", "after", "and", "a value", "account"};
    auto result = find(lst.cbegin(), lst.cend(), val);
    // 报告结果
    cout << "The value \"" << val
        << (result == lst.cend()? "\" is not present" : "\" is present") << endl;
    return 0;
}
