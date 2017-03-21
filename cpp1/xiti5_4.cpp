#include <iostream>
#include <cmath>
using namespace std;

class Equation
{
private:
    double a,b,c;
    int flag;
    double root1,root2;
    void solve(); //解方程
public:
    Equation() = default;
    Equation(const double &x, const double &y, const double &z):a(x),b(y),c(z){}
    friend istream &operator>>(istream &is, Equation &e);
    friend ostream &operator<<(ostream &os, Equation &e);
};

void Equation::solve()
{
    double delta = b*b-4*a*c;
    if (delta > 0) //该方程有两个不相等实根
    {
        root1 = (-b+sqrt(delta))/(2*a);
        root2 = (-b-sqrt(delta))/(2*a);
        flag = 1;
    }
    else if (delta == 0) // 该方程有两个相等实根
    {
        root1 = root2 = -b/(2*a);
        flag = 2;
    }
    else // 该方程有一对共轭复根
        flag = 3;
}

ostream &operator<<(ostream &os, Equation &e)
{
    e.solve(); //解方程
    if (e.flag == 1)
        os << e.flag << "\n" << e.root1 << "  " << e.root2;
    else if(e.flag == 2)
        os << e.flag << "\n" << e.root1;
    else
        os << e.flag;
    return os;
}

istream &operator>>(istream &is, Equation &e)
{
    is >> e.a >> e.b >> e.c;
    return is;
}

int main()
{
    Equation eq1;
    while(cin >> eq1)
        cout << eq1 << endl;
    return 0;
}
