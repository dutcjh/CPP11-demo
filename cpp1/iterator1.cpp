#include <iostream>
#include <cctype>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> s;
    for (int i = 1; i != 11; ++i)
        s.push_back(i);
    for(auto c : s)
        cout << c << "\t";
    cout << endl;
    for (auto it = s.begin(); it != s.end(); ++it)
        *it *= 2;
    for(auto c : s)
        cout << c << "\t";
    cout << endl;
    cout << s.cend() - s.cbegin() << endl;
    cout << *(s.begin()+s.size()/2) << endl;
    return 0;
}
