#include<iostream>
#include<iterator>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
    istream_iterator<int> in(cin), eof;
    list<int> lst(in, eof);

    ostream_iterator<int> out(cout, " ");
    copy(lst.begin(), lst.end(), out);
    cout << endl;

    return 0;
}

