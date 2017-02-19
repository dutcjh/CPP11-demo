#include <iostream>
#include <string>

using namespace std;

int main()
{
    int sz{0};
    begin:
        cin >> sz;
        if (sz <= 0)
            goto begin;
        else
            cout << sz << endl;
    return 0;
}
