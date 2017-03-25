#include<iostream>
using namespace std;

class R
{
public:
    R(int r1, int r2):r1(r1),r2(r2) {}
    void print() { cout << r1 << ":" << r2 << endl; }
    void print() const { cout << r1 << ";" << r2 << endl; }
private:
    int r1, r2;
};

int main()
{
    R a(5,4);
    a.print();
    const R b(20, 52);
    b.print();
    return 0;
}


