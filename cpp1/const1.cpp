#include <iostream>

using namespace std;
int main()
{
    const int bufSize = 512;
    cout << "Buffer size is " << bufSize << endl;
    int s = 42;
    int &rs = s;
    const int &r = s;
    rs = 300;
    cout << r << endl;
    s = 320;
    cout << r << endl;
    int errNumb = 10;
    int *const curErr = &errNumb;
    cout << *curErr << endl;
    const double pi = 3.14159;
    const double *const pip = &pi;
    cout << "pip " << pip << "-->" << *pip << endl;
    if (*curErr)
    {
        *curErr = 0;
    }
    cout << errNumb << endl;
    return 0;
}
