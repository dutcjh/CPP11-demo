// 求3个数中最大数（分别考虑整数、实数、长整数的情况）。
// 要求用函数重载来实现。
#include<iostream>
using namespace std;
#define MAX(a,b) ((a>b)?a:b)

int max(int a,int b,int c){ return MAX(MAX(a,b),c); }
double max(double a,double b,double c){ return MAX(MAX(a,b),c); }
long max(long a,long b,long c){ return MAX(MAX(a,b),c); }

int main()
{
    unsigned nCase;
    cout << "Test int max(int,int,int);" << endl;
    cin >> nCase; // 输入测试次数
    cout << "---------------------------------------" << endl;
    int ia,ib,ic;
    for (unsigned i = 0; i < nCase; ++i)
    {
        cin >> ia >> ib >> ic;
        cout << "Max: " << max(ia,ib,ic) << endl;
    }

    cout << "=======================================" << endl;
    cout << "Test double max(double,double,double);" << endl;
    cin >> nCase; // 输入测试次数
    cout << "---------------------------------------" << endl;
    double da,db,dc;
    for (unsigned i = 0; i < nCase; ++i)
    {
        cin >> da >> db >> dc;
        cout << "Max: " << max(da,db,dc) << endl;
    }

    cout << "=======================================" << endl;
    cout << "Test long max(long,long,long);" << endl;
    cin >> nCase; // 输入测试次数
    cout << "---------------------------------------" << endl;
    long la,lb,lc;
    for (unsigned i = 0; i < nCase; ++i)
    {
        cin >> la >> lb >> lc;
        cout << "Max: " << max(la,lb,lc) << endl;
    }

    return 0;
}

