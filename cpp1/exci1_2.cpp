#include<iostream>

using namespace std;
int main()
{
    int a = 1, b, c;
    a = (b = a+1, c = b+2, a = c+1) + a;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    return 0;
}
