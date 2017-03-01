#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char day[10] = "Sunday";
    strcpy(day, "Wednesday");
    cout << day << endl;
    return 0;
}
