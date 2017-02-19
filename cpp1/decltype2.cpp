#include <iostream>

using namespace std;

int main()
{
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    cout << a << "-" << b << "-" << c << "-" << d << endl;
    ++c;
    cout << a << "-" << b << "-" << c << "-" << d << endl;
    ++d;
    cout << a << "-" << b << "-" << c << "-" << d << endl;
    return 0;
}
