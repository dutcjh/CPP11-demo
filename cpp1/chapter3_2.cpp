#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int a = 1234567890;
    double b = 123.45;
    cout << setw(20) << a << endl;
    cout << setw(15) << a << endl;
    cout << setw(10) << a << endl;
    cout << setw(10) << b << endl;
    cout << setw(8) << b << endl;
    cout << setw(6) << b << endl;
    cout << setw(4) << b << endl;
    cout << setw(2) << b << endl;

    return 0;
}
