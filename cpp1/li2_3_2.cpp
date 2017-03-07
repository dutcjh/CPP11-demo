//校门外的树
#include<iostream>
using namespace std;

int main()
{
    unsigned L{0}, M{0};
    cin >> L >> M;
    bool *trees = new bool[L+1]();
    for (unsigned i = 0; i < M; ++i)
    {
        unsigned a{0}, b{0};
        cin >> a >> b;
        for (unsigned j = a; j <= b; ++j)
            *(trees+j) = true;
    }
    unsigned count{0};
    for (unsigned i = 0; i <= L; ++i)
        if (!(*(trees+i))) ++count;
    cout << count << endl;
    delete[] trees;
    return 0;
}
