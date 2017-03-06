#include<iostream>
using namespace std;

typedef long long DST;

DST get_num(DST a, DST b, DST &x, DST &y)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        return a;
    }
    DST r = get_num(b, a%b, y, x);
    y -= x*a/b;
    return r;
}

int main()
{
    DST x, y, m, n, l;
    cin >> x >> y >> m >> n >> l;
    if (n<m)
    {
        swap(x,y);
        swap(n,m);
    }
    DST xx = 0, yy = 0;
    DST d = get_num(n-m, l, xx, yy);
    x -= y;
    if(x%d) cout << "Impossible" << endl;
    else
    {
        xx *= x/d;
        xx = (xx%l+l)%l;
        cout << xx << endl;
    }
    return 0;
}
