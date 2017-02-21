#include <iostream>
#include <string>
using namespace std;

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    string s1{"abcdefg"}, s2{"abcdefgh"};
    if(isShorter(s1, s2))
        cout << "s1 is shorter than s2. " << endl;
    else
        cout << "s2 is shorter than s1. " << endl;
    return 0;
}
