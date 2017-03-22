#include<iostream>
#include<algorithm>
using namespace std;
template<typename T>

void print(T *st, T *ed)
{
    for(T *it = st; it != ed; ++it)
        cout << *it << " ";
}

int main()
{
    int a1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2[2*sizeof(a1)/sizeof(*a1)];
    auto ret = copy(begin(a1), end(a1), a2);
    print(begin(a2), ret);
    cout << endl;
    auto ret2 = copy(begin(a1), end(a1), ret);
    print(begin(a2), ret2);
    cout << endl;
    return 0;
}

