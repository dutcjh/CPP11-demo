#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string s1 = "abcdefgh";
    cout << "s1: " << s1 << endl;
    cout << "char of s1: " << s1.size() << endl;
    cout << s1[2] << endl;
    string s2 = "ijklmn";
    s2 += "opqrst";
    cout << "s2: " << s2 << endl;
    cout << "s1+s2: " << s1+s2+"uvwxyz" << endl;
    string alphabet = s1+s2+"uvwxyz";
    cout << "alphabet: " << alphabet << endl;
    for (auto c: alphabet)
        cout << char(toupper(c));
    cout << endl;
    cout << alphabet.length() << endl;

    return 0;
}
