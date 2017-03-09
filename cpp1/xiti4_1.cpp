// 输入一个三角形的3边长度，判断该三角形是否为直角三角形，
// 若是则输出True，若不是则输出False。
#include<iostream>
using namespace std;

bool right_triangle(int a, int b, int c)
{
    if (a*a + b*b == c*c) return true;
    if (b*b + c*c == a*a) return true;
    if (c*c + a*a == b*b) return true;
    return false;
}

int main()
{
    int a, b, c;
    cout << "Please input three sides' length of a triangle: " << endl;
    while(cin >> a >> b >> c)
        cout << (right_triangle(a,b,c)?"True":"False") << endl;
    return 0;
}


