#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> num;
    for(int i = 0; i < 10; ++i)
        num.push_back(i);
    for(auto &i : num)
        i *= i;
    for(auto i : num)
        cout << i << " ";
    cout << endl;
    return 0;
}
