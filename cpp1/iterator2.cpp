#include <iostream>
#include <cctype>
#include <vector>
#include <string>

using namespace std;

int main()
{
    const vector<int> text {0,1,3,4,6,7,8,10,14,19};
    auto beg = text.cbegin(), end = text.cend();
    auto mid = text.cbegin() +(end - beg)/2;
    const int sought = 2;
    while (mid != end && *mid != sought)
    {
        if (sought < *mid)
            end = mid;
        else
            beg = mid + 1;
        mid = beg + (end - beg)/2;
    }
    if (mid == end)
        cout << "No this number!" << endl;
    else
        cout << "There is this number: " << *mid << endl;
    return 0;
}

