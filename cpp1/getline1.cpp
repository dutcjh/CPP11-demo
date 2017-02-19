#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line) && line != "_")
    {
        if (!line.empty())
            cout << line << "(" << line.size() << ")" << endl;
    }


    return 0;
}
