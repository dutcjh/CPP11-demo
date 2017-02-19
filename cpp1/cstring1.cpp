#include <iostream>
#include <cstring>

using namespace std;
int main()
{
    const char ca[] = {'h','e','l','l','o','\0'};
    const char *cp = ca;
    while(*cp)
    {
        cout << *cp << endl;
        ++cp;
    }
}
