#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    double a = 1.234567;
    double b = 1234.567;
    cout << a << endl;
    cout << b << endl;
    cout << setprecision(3) << a << endl;
    cout << setprecision(3) << b << endl;

    return 0;
}
