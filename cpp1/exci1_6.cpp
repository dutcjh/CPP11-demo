#include<iostream>

using namespace std;

int main()
{
   int  a,b,c;
   a=1,b=2,c=a+b+3;
   cout<<a<<','<<b<<','<<c<<endl; // 1 2 6
   c=(a++,a+=b,a-b);
   cout<<a<<','<<b<<','<<c<<endl; // 4 2 2
   return 0;
}
