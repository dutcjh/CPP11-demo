#include<iostream>
using namespace std;

unsigned get_stack(double dst)
{
    unsigned num = 1;
    while(dst>=0)
    {
        dst -= 1.0/(++num);
    }
    return num-1;
}

int main()
{
    double d = 0;
    cin >> d;
    while(d > 0.0001)
    {
        cout << get_stack(d) << " card(s)" << endl;
        cin >> d;
    }
    return 0;
}
