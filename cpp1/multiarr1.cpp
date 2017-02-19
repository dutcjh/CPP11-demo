#include <iostream>
#include <array>

using namespace std;

int main()
{
    const unsigned rn = 3, cn = 4;
    int ia[rn][cn] = {
                    {0,1,2,3},
                    {4,5,6,7},
                    {8,9,10,11}
                   };
    for (unsigned i = 0; i != rn; ++i)
    {
        for (unsigned j = 0; j != cn; ++j)
        {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
