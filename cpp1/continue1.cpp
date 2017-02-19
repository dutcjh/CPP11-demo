#include <iostream>
#include <string>

using namespace std;

int main()
{
    string buf;
    while (cin >> buf && !buf.empty())
    {
        if (buf[0] != '_')
            continue;
        cout << buf << endl;
    }
    return 0;
}
