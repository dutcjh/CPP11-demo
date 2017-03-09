#include<iostream>
using namespace std;

bool right_triangle(const int a, const int b, const int c)
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



