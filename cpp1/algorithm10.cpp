#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
template<typename T> ostream &operator<<(ostream &os, const list<T> &lst)
{
    for(auto i : lst) os << i << " ";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec)
{
    for(auto i : vec) os << i << " ";
    return os;
}
int main()
{
    list<int> ilst = { 1,2,3,0,1,2,6,0,0,1};
    replace(ilst.begin(), ilst.end(), 0, 42);
    cout << "ilst: " << ilst << endl;
    vector<int> ivec;
    replace_copy(ilst.begin(), ilst.end(), back_inserter(ivec), 42, 0);
    cout << "ivec: " << ivec << endl;
    cout << "ilst: " << ilst << endl;
    return 0;
}

