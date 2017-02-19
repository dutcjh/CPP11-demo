#include <iostream>

using namespace std;
int main()
{
    int i{0}, &r{i};
    auto a = r;
    i = 8;
    cout << "a " << a << endl;
    cout << "r " << r << endl;
    const int ci = i, &cr = ci;
    cout << "ci " << cr << endl;
    auto b = cr;
    cout << "b " << b << endl;
    b = 10;
    cout << "b " << b << endl;
    cout << "ci " << cr << endl;
    auto d = &i;
    cout << "d " << *d << endl;
    auto e = &ci;
    cout << "e " << *e << endl;
    e = &b;
    cout << "e " << *e << endl;
    const auto f = ci;
    cout << "f " << f << endl;
    auto &g = ci;
    const auto &j = 42;
    auto k = ci, &l = i;
    auto &n = i, *p2 = &i;
    return 0;
}
