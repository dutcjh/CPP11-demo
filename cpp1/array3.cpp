#include <iostream>
#include <array>

using namespace std;

int main()
{
    const unsigned sz = 10;
    int arr[sz] = {0,1,2,3,4,5,6,7,8,9};
    int *b = arr, *e = arr + sz;
    while (b < e)
    {
        cout << *b << " ";
        ++b;
    }
    cout << endl;

    return 0;
}
