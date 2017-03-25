#include<iostream>
using namespace std;

class A
{
public:
    A(int i):a(i){ }
    void print() { cout << a << ":" << b << endl; }
private:
    const int a;
    static const int b;
};
const int A::b = 10;

int main()
{
    A a1(100), a2(0);
    a1.print();
    a2.print();
    A a[] = {100,0};
    a[0].print();
    a[1].print();
    return 0;
}

