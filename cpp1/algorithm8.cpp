#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template <typename T>

ostream &operator<<(ostream &os, const vector<T> &vec)
{
    for(auto i : vec) os << i << " ";
    return os;
}

int main()
{
    vector<int> vec;
    auto it = back_inserter(vec);
    *it = 42;
    *it = 54;
    *it = 66;
    cout << vec << endl;
    fill_n(*it, 7, 0);
    cout << vec << endl;
    return 0;
}

