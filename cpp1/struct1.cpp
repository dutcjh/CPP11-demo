#include <iostream>
#include <string>
#include "Sales_data.h"

using namespace std;
int main()
{
    Sales_data book1;
    book1.bookNo = "13231-X-701-01";
    cout << "book no." << book1.bookNo << endl;
    cout << "units_sold." << book1.units_sold << endl;
    cout << "revenue." << book1.revenue << endl;
    return 0;
}
