// ��1~10�и�������ƽ����Ҫ������������ʵ�֡�
#include<iostream>
#include<iomanip>
using namespace std;

inline int x_square(int x) { return x*x; }

int main()
{
    for (int i = 1; i <= 10; ++i)
        cout << setw(3) << i << "^2 = " << x_square(i) << endl;
    return 0;
}


