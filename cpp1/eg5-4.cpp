// eg5-4.cpp
#include<iostream>
#include "tdate.h"
using namespace std;

int main()
{
    Tdate date1(2016, 9, 1), date2(2017, 3, 15);
    int leap = date1.IsLeapYear();
    cout << leap << endl;
    date1.print();
    leap = date2.IsLeapYear();
    cout << leap << endl;
    date2.print();
    return 0;
}
