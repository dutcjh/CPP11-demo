#include <iostream>

using namespace std;

int main()
{
    int n = 0, i = 42;
    int *p = &n, *q = &i;
    *p = 42;
    p = q;
    cout << "*p = " << i << endl;
    cout << "*q = " << n << endl;
    return 0;
}
