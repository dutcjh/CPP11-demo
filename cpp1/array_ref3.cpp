#include<iostream>

using namespace std;

void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
        cout << ia[i] << " ";
}

int main()
{
    int s[] = {1,2,3,4,5,6,7,8};
    print(s, end(s) - begin(s));
    cout << endl;
    return 0;
}
