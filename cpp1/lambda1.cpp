#include<iostream>
using namespace std;

int main()
{
    auto f = [](int a, int b = 1) { return a*b; };
    cout << f(6) << "  " << f(3,9) << endl;
    cout << [f](const int a) { return f(a,a); }(9) << endl;
    return 0;
}
