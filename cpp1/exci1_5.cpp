#include  <iostream>

using namespace std;

int main()
{
    int  a=3,b=4,c;
    c=a>b? ++a:++b;
    cout<<a<<","<<b<<","<<c<<endl; // 3 5 5
    c=a-b?a-3?b:b-a:a;
    cout<<a<<","<<b<<","<<c<<endl; // 3 5 2
    return 0;
}
