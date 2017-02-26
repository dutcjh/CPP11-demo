#include <iostream>
#include <string>

using namespace std;

class Sales
{
public:
    string isbn;
    double units_sold;
    double revenue;
public:
    Sales(string isb, double units, double rev);
    double avg_price()
    {
        return revenue/units_sold;
    }

};

inline Sales::Sales(string isb, double units, double rev)
{
    isbn = isb;
    units_sold = units;
    revenue = rev;
}

ostream &operator<<(ostream &os, const Sales &item)
{
    os << item.isbn;
    return os;
}

int main()
{
    Sales items("123456789",5,120.0);
    cout << items << endl;
    return 0;
}
