#include <iostream>

using namespace std;
int main()
{
    typedef double wages;
    typedef wages base, *p;
    wages banana = 12;
    base apple = 10;
    p pb = &banana, pa = &apple;
    cout << "Banana: " << *pb << endl;
    cout << "Apple: " << *pa << endl;
    const p cpa = &apple;
    cout << "Constant apple: " << *cpa << endl;
    const p *pp = &cpa;
    cout << "Constant apple: " << **pp << endl;
    **pp = 20;
    cout << "Constant apple: " << *cpa << endl;
    auto sum = apple + banana;
    cout << "sum: " << sum << endl;
    auto i = 1, *pi = &i;
    cout << "i: " << *pi << endl;
    cout << "size of i: " << sizeof(i) << endl;
    return 0;
}

