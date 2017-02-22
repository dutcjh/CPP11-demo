#include<iostream>

using namespace std;

void print(const int *beg, const int *end)
{
    while (beg != end)
        cout << *beg++ << "  ";
}
int main()
{
    int s[] = {1,2,3,4,5,6};
    print(begin(s),end(s));
    cout << endl;
    return 0;
}
