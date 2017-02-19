#include <iostream>

using namespace std;
int main()
{
    constexpr int mf = 20;
    constexpr int limit = mf + 1;
    constexpr int sz = sizeof(long long);
    cout << sz << endl;
    int null = 0, *p = &null;
    return 0;
}
