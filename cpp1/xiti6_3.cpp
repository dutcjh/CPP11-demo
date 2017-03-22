#include<iostream>
using namespace std;

class A
{
public:
    int x;
    static int y;
    const int z;
    int const w;
    A(const int z1, const int w1): z(z1),w(w1){}
};
int A::y = 0;


int main()
{
    A a(1,2);  a.x = 1;  A::y = 1;

    return 0;
}
