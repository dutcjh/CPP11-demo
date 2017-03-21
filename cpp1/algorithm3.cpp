#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int val = 42; // 我们将查找的值
    // 如果在vec中找到想要的元素，则返回结果指向它，否则返回结果为vec.cend()
    vector<int> vec = {2,3,45,44,45,12,20,22,45,42,13};
    auto ia = vec.cbegin();
    auto result = find(ia+1, ia+5, val);
    // 报告结果
    cout << "The value " << val
        << (result == ia+5? " is not present" : " is present") << endl;
    return 0;
}
