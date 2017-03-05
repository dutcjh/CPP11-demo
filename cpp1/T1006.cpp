#include<iostream>

using namespace std;

int main()
{
    int p,e,i,d,n=1;
    while(cin >> p >> e >> i >> d)
    {
        if((p == -1)&&(e == -1)&&(i==-1)&&(d==-1))
            break;
        int day = (5544*p+14421*e+1288*i-d)%(23*28*33);
        if(day <= 0)
            cout<<"Case "<< n++ <<": the next triple peak occurs in "<< 21252-d <<" days."<<endl;
        else
            cout<<"Case "<< n++ <<": the next triple peak occurs in "<< day <<" days."<<endl;
    }
    return 0;
}
