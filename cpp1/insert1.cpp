#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

template<typename T> ostream &operator<<(ostream &os, const list<T> &lst)
{
    for(const auto &i : lst) os << i << " ";
    return os;
}

int main()
{
    list<int> lst = {1,2,3,4};
    list<int> lst2, lst3, lst4;
    cout << "1: " << lst << endl;
    copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
    cout << "2: " << lst2 << endl;
    copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
    cout << "3: " << lst3 << endl;
    copy(lst.cbegin(), lst.cend(), back_inserter(lst4));
    cout << "4: " << lst4 << endl;
    return 0;
}

