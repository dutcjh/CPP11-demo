#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

ostream &operator<<(ostream &os, vector<int> vec)
{
    for(auto i : vec) os << i << " ";
    return os;
}

int main()
{
    vector<int> vec = {1,2,3,4,5};
    cout << vec << endl;
    fill(vec.begin(), vec.end(), 0);
    cout << vec << endl;
    fill(vec.begin(), vec.begin()+vec.size()/2, 10);
    cout << vec << endl;
    return 0;
}


