#include<iostream>

using namespace std;

void print(int (&arr)[8])
{
    for (auto elem : arr)
        cout << elem << " ";
}

int main()
{
    int s[] = {1,2,3,4,5,6,7,8};
    print(s);
    cout << endl;
    return 0;
}
