#include<iostream>
#include<iterator>
#include<list>
using namespace std;

int main()
{
    istream_iterator<int> in(cin), eof;
    list<int> lst(in, eof);

    ostream_iterator<int> out(cout, " ");
    for (auto e:lst) *out++ = e; //�ȼ���*out = e;
    cout << endl;
    return 0;
}

