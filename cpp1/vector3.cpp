#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    for(int i = 1; i < 10; ++i)
        v.push_back(i);
    cout << v.size() << endl;
    v.pop_back();
    cout << v.size() << endl;
    for(int i = 1; i < 5; ++i)
    {
        v.pop_back();
        cout << v.size() << endl;
    }
    return 0;
}
