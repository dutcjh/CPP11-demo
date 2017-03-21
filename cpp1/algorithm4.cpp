#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> vec = {2,3,45,44,45,12,20,22,45,42,13};
    int sum = accumulate(vec.cbegin(), vec.cend(), 0);
    cout << "The sum of value: " << sum << endl;
    return 0;
}
