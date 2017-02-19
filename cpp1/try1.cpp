#include <iostream>
#include "Sales_item.h"
#include <stdexcept>

using namespace std;

int main()
{
    Sales_item item1, item2;
    while (cin >> item1 >> item2)
    {
        try
        {
            if (item1.isbn != item2.isbn)
                throw runtime_error("Data must refer to same ISBN!");
            cout << item1 + item2 << endl;
            break;
        }
        catch(runtime_error err)
        {
            cout << err.what() << endl << "Try Again? Enter y or n: ";
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
            else
                cout << "Please Enter two items: " << endl;
        }
    }

    return 0;
}
