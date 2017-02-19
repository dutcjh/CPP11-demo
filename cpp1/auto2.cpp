#include <iostream>

using namespace std;
int main()
{
    const int i = 42;
    auto j = i; // j --> int
    const auto &k = i; // k reference of constant int
    auto *p = &i; //  const int *p = &i
    const auto j2 = i, &k2 = i;
    return 0;
}
