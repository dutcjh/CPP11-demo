// 用递归方法求x^n，x和n由键盘输入。
#include<iostream>
using namespace std;

long xn(long,long);

int main()
{
    cout << "Calculate x^n. Please input x and n: " << endl;
    long x, n;
    cin >> x >> n;
    cout << x << "^" << n << " = " << xn(x,n) << endl;
    return 0;
}

long xn(long x,long n)
{
    if (n == 1)
        return x;
    else
        return x*xn(x, n-1);
}
