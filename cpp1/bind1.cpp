#include <iostream>
#include <string>
#include <functional>

using namespace std;
using namespace std::placeholders; // _n, ±ØÐëÓÐÕâ¾ä

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

int f(int a, int b, int c, int d, int f)
{
    return a*10000+b*1000+c*100+d*10+f;
}

int main()
{
    string s = "hello world!";
    auto check6 = bind(check_size, _1, 6);
    bool b1 = check6(s);
    cout << boolalpha << b1 << endl;
    int a = 0, b = 0, c = 0;
    auto g = bind(f,a,b,_2,c,_1);
    cout << g(1,2) << endl;
    return 0;
}
