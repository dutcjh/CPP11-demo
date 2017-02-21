#include <iostream>
#include <string>
using namespace std;

string::size_type find_char(const string &s, const char c,
                            string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i)
    {
        if (s[i] == c)
        {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}

int main()
{
    string s1 = "beautiful and handsome";
    char chr = 'a';
    string::size_type occurs = 0, lst = 0;
    lst = find_char(s1, chr, occurs);
    cout << occurs << endl;
    cout << lst << endl;
    return 0;
}
