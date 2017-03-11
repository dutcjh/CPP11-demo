//tdate.h
#ifndef __TDATE_H__
#define __TDATE_H__
#include <iostream>
using namespace std;
class Tdate
{
public:
    Tdate(int, int, int);
    ~Tdate(){cout << "Destructor call.\n";}
    int IsLeapYear();
    void print();
    friend ostream &operator<< (ostream &os, const Tdate &t);
private:
    int year, month, day;
};

Tdate::Tdate(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

int Tdate::IsLeapYear()
{
    return (!(year%4)&&(year%100))||(!(year%400));
}

void Tdate::print()
{
    cout << year << " " << month << " " << day << endl;
}

ostream &operator<< (ostream &os, const Tdate &t)
{
    os << t.year << "-" << t.month << "-" << t.day;
    return os;
}

#endif // __TDATE_H__
