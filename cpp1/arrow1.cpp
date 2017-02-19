#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "a string", *p = &s1;
    auto n = s1.size();
    cout << n << endl;
    n = (*p).size();
    cout << n << endl;
    n = p -> size();
    cout << n << endl;
    return 0;
}
