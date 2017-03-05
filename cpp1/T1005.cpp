#include<iostream>
#include<cmath>

using namespace std;

const double PERY = 50;
const double PI = 3.1415926;
unsigned get_year(double dst)
{
    unsigned year = 0;
    while(PI*dst*dst/2 > year*PERY)
    {
        year++;
    }
    return year;
}

int main()
{
    unsigned N = 0;
    double x = 0.0, y = 0.0, dst = 0.0;
    cin >> N;
    for(unsigned i = 0; i < N; ++i)
    {
        cin >> x >> y;
        dst = sqrt(x*x + y*y);
        cout << "Property " << i+1 << ": This property will begin eroding in year ";
        cout << get_year(dst) << "." << endl;
    }
    cout << "END OF OUTPUT." << endl;
    return 0;
}
