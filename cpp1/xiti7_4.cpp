#include<iostream>
#include<string>
using namespace std;

void reserve(string &s)
{
    for(size_t i = 0; i < s.length()/2; ++i)
    {
        char t = s[i];
        s[i] = s[s.length()-1-i];
        s[s.length()-1-i] = t;
    }
}

int main()
{
    string s;
    getline(cin, s);//ÊäÈë×Ö·û´®£¬Ö§³Ö¿Õ¸ñ
    reserve(s); // ÄæÐò
    cout << s << endl; //Êä³ö
    return 0;
}
