#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    const string s("hello world!!!");
    string result;
    for (auto &c : s)
        if (!ispunct(c))
            result += c;
    cout << result << endl;
    return 0;
}
