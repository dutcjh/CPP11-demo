#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string line = "FIRST,MIDDLE,LAST";
    auto comma = find(line.crbegin(), line.crend(), ',');
    cout << string(line.crbegin(), comma) << endl;
    cout << string(comma.base(), line.cend()) << endl;
}
