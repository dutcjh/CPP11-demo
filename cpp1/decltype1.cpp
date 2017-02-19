#include <iostream>

using namespace std;

int f()
{
    return 0.1;
}

int main()
{
    decltype(f()) sum = 1.2;
    cout << "size of sum: " << sizeof(sum) << " -- " << sum << endl;
    decltype(sum) sum2 = 4.2;
    cout << "size of sum2: " << sizeof(sum2) << " -- " << sum2 << endl;
    const int ci = 0, &cj = ci;
    decltype(ci) x = 0;
    decltype(cj) y = x;
    cout << "size of y: " << sizeof(y) << " -- " << y << endl;
    // decltype(cj) z;
    decltype((ci)) z = 9;
    return 0;
}
