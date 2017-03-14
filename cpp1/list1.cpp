#include<iostream>
#include<list>
#include<vector>
using namespace std;

int main()
{
    list<int> lst;
    for(unsigned i = 0; i < 10; ++i)
        lst.push_back(i);
    cout << lst.size() << ": ";
    for(auto i : lst)
        cout << i << " ";
    cout << endl;
    for(unsigned i = 1; i < 10; ++i)
        lst.push_front(i);
    cout << lst.size() << ": ";
    for(auto i : lst)
        cout << i << " ";
    cout << endl;
    // ²åÈë²Ù×÷
    auto iter = lst.begin();
    for(unsigned i = 10; i < 20; ++i)
        iter = lst.insert(iter, i);

    cout << lst.size() << ": ";
    while(iter != lst.cend())
        cout << *iter++ << " ";
    cout << endl;

    auto it = lst.begin();
    while(it != lst.cend())
        if(*it % 2)
            it = lst.erase(it);
        else
            ++it;
    cout << lst.size() << ": ";
    for(auto i : lst)
        cout << i << " ";
    cout << endl;

    vector<int> vec;
    it = lst.begin();
    while(it != lst.cend())
        vec.push_back(*it++);

    cout << "vector: " << endl;
    cout << vec.size() << ": ";
    for(auto i : vec)
        cout << i << " ";
    cout << endl;
    return 0;
}
