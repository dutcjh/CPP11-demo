#include <iostream>
#include <array>
#include <string>

using namespace std;

int main()
{
    unsigned scores[11] = {};
    unsigned grade;
    while (cin >> grade)
        if (grade <= 100)
            ++scores[grade/10];
    for (auto s : scores)
        cout << s << " ";
    cout << endl;
    cout << s << endl;
    return 0;
}
