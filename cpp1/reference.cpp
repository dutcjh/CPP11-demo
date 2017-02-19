#include <iostream>
// 引用即别名！
using namespace std;
int main()
{
    int ival = 1024;
    int &refval = ival;
    int ival2 = refval;
    cout << "val: " << ival << endl;
    cout << "val2: " << ival2 << endl;
    cout << "refval: " << refval << endl;
    int &refval2 = refval;
    cout << "refval2: " << refval2 << endl;

    ival = 256;
    cout << "val: " << ival << endl;
    cout << "val2: " << ival2 << endl;
    cout << "refval: " << refval << endl;
    cout << "refval2: " << refval2 << endl;

    refval = 128;
    cout << "val: " << ival << endl;
    cout << "val2: " << ival2 << endl;
    cout << "refval: " << refval << endl;
    cout << "refval2: " << refval2 << endl;
    return 0;
}
