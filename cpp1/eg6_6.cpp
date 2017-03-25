#include<iostream>
using namespace std;

class A
{
    friend class B;
public:
    void display(){ cout << x << endl; };
private:
    int x;
};

class B
{
public:
    void set(int i) { a.x = i; }
    void display(){ a.display(); }
private:
    A a;
};

int main()
{
    B b;
    b.set(5);
    b.display();
}
