#include <iostream>
#include <array>
#include <vector>

using namespace std;
int main()
{
    const unsigned rn = 3, cn = 4;
    using int_array = int[cn];
    // typedef int int_array[4];
    int_array ia[rn] = {};
    for (auto p = ia; p != ia + rn; ++p)
    {
        for (auto q = *p; q != *p + cn; ++q)
            cout << *q << ' ';
        cout << endl;
    }
    vector<int> va;
    for (int i = 0; i != 10; ++i)
        va.push_back(i);
    for (auto i : va)
        cout << i << ' ';
    cout << endl;
    decltype(va) temp(va.begin(), va.end()-1);
    for (auto i : temp)
        cout << i << ' ';
    cout << endl;
    return 0;
}
