//ผฆอรอฌมýฮสฬโ
#include<iostream>
using namespace std;

int main()
{
    unsigned num = 0;
    cin >> num;
    for (unsigned i = 0; i < num; ++i)
    {
        int a;
        cin >> a;
        if (a%2)
            cout << "0 0" << endl;
        else if (a%4)
            cout << a/4+1 << ' ' << a/2 << endl;
        else
            cout << a/4 << ' ' << a/2 << endl;
    }
    return 0;
}
