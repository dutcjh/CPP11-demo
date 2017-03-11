#include<iostream>
using namespace std;

class point
{
    int x, y;
public:
    point(int vx, int vy):x(vx), y(vy){};
    point(const point &p):x(p.x), y(p.y){};
    void print(){cout << x << " " << y << endl;}
};

int main()
{
    point p1(10,20);
    point p2(p1);
    point p3 = p1;
    p1.print();
    p2.print();
    p3.print();
    return 0;
}
