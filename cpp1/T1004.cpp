#include<iostream>
using namespace std;

int main()
{
    double m = 0, sum = 0;
    for(int i = 0; i < 12; ++i)
    {
        cin >> m;
        sum += m;
    }
    cout << "$" << sum/12 << endl;
    return 0;
}
