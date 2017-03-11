// eg5-4.cpp
#include<iostream>
#include "tdate.h"
using namespace std;

int main()
{
    Tdate today(2016, 2, 20), tomorrow(2016, 2, 21);
    cout << "today is " << today << endl;
    cout << "tomorrow is " << tomorrow << endl;
    return 0;
}
