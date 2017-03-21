#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<string> v1 = {"I ", "am ", "a ", "student."};
    vector<string> v2 = {"I ", "am ", "not ", "a ", "student."};
    bool eq = equal(v1.cbegin(), v1.cend(), v2.cbegin());
    cout << boolalpha << eq << endl;
    return 0;
}

