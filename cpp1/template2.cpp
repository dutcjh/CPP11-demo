#include<iostream>
#include<string>
using namespace std;

template <typename T> T foo(T *p)
{
    T tmp = *p;
    return tmp;
}

int main()
{
    const string s = "Hello, world!", *p = &s;
    cout << foo(p) << endl;
    return 0;
}
