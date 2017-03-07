//校门外的树
#include<iostream>
using namespace std;
constexpr unsigned TOTAL = 10001;

int main()
{
    bool trees[TOTAL] = {};
    unsigned L{0}, M{0};
    cin >> L >> M;
    for (unsigned i = 0; i < M; ++i)
    {
        unsigned a{0}, b{0};
        cin >> a >> b;
        for (unsigned j = a; j <= b; ++j)
            trees[j] = true;
    }
    unsigned count{0};
    for (unsigned i = 0; i <= L; ++i)
        if (!trees[i]) ++count;
    cout << count << endl;
    return 0;
}
