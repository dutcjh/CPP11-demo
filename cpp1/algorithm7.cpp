#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template <typename T>

ostream &operator<<(ostream &os, vector<T> vec)
{
    for(auto i : vec) os << i << " ";
    return os;
}

int main()
{
    vector<int> vec = {1,2,3};
    fill_n(vec.begin(), vec.size(), 0);  // 安全的
    cout << vec << endl;
    fill_n(vec.begin(), 2, 1);
    cout << vec << endl;
    // fill_n(vec.begin(), 4, 0); // 灾难！！！
    // cout << vec << endl;
    return 0;
}

