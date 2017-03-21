// 10.1 概述
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int val = 42; // 我们将查找的值
    // 如果在vec中找到想要的元素，则返回结果指向它，否则返回结果为vec.cend()
    vector<int> vec = {2,3,45,44,42,12,20,22,45,42,13};
    auto result = find(vec.cbegin(), vec.cend(), val);
    // 报告结果
    cout << "The value " << val
        << (result == vec.cend()? " is not present" : " is present") << endl;
    return 0;
}
