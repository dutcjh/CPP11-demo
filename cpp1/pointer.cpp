#include <iostream>

using namespace std;
int main()
{
    int i = 10;
    int &refp = i, *p = &refp, **p2 = &p;
    refp = refp * refp;
    cout << &refp << "-->" << refp << endl;
    cout << p << "-->" << *p << endl;
    cout << p2 << "-->" << *p2 << "-->" << **p2 << endl;
    int *&r = p; //指针的引用,从右往左读
    // int &*r2 = p; //引用不是对象，没有指针
    cout << *r << endl;
    // cout << *r2 << endl;
    int **&rr = p2;
    cout << **rr << endl;
    return 0;
}
