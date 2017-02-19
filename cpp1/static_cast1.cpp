#include <iostream>

using namespace std;

int main()
{
    double d = 1.2;
    void *p = &d;
    double *dp = static_cast<double*>(p);
    cout << *dp << endl;
    char c = 'a';
    const char *pc = &c;
    char *cc = const_cast<char*>(pc);
    cout << *cc << endl;
    *cc = 'b';
    cout << *cc << endl;
    return 0;
}
