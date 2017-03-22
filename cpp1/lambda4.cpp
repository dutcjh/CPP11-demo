#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec)
{
    for(const auto &i : vec) os << i << " ";
    return os;
}

int main()
{
    vector<int> vi = {1,2,-3,4,-5,-6,-7,-8};
    cout << "origin: " << vi << endl;
//    transform(vi.begin(), vi.end(), vi.begin(),
//              [](int i) { return i < 0 ? -i : i; });
    transform(vi.begin(), vi.end(), vi.begin(),
              [](int i) -> int
              { if(i<0) return -i; else return i;});
    cout << "transform: " << vi << endl;
    return 0;
}



