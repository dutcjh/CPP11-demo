#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1;
    string s2(s1);
    string s3("hiya");
    string s4(10,'c');
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    bool a = s3 == s4;
    cout << a << endl;
    return 0;
}
