//ÆåÅÌÉÏµÄ¾àÀë
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    unsigned num = 0;
    cin >> num;
    for (unsigned i = 0; i < num; ++i)
    {
        char beg[3],end[3];
        cin >> beg >> end;
        const int x = abs(beg[0]-end[0]);
        const int y = abs(beg[1]-end[1]);
        if (x==0 && y==0) cout << "0 0 0 0" << endl;
        else
        {
            cout << (x>y?x:y) << ' ';
            cout << ((x == y || x == 0 || y==0)?1:2) << ' ';
            cout << ((x == 0 || y==0)?1:2) << ' ';
            cout << (((x-y)%2 != 0)?"Inf":(x==y?"1":"2")) << endl;
        }
    }
    return 0;
}

