#include<iostream>
#include<iterator>
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
   /* list<int> lst;
    istream_iterator<int> in_iter(cin);//从cin读取int
    istream_iterator<int> eof; //尾后迭代器
    while(in_iter != eof)
        lst.push_back(*in_iter++);
    cout << lst << endl;
    istream_iterator<int> in(cin), eof;
    list<int> lst2(in, eof);
    cout << lst2 << endl;*/
    istream_iterator<int> in(cin),eof;
    cout << accumulate(in, eof, 0) << endl;
    return 0;
}

