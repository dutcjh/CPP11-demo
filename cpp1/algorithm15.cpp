#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
using namespace std::placeholders;

ostream &print(ostream &os, const string &s, char c)
{
    return os << s << c;
}

int main()
{
    vector<string> words;
    // the quick red fox jumps over the slow red turtle
    string temp;
    while(cin >> temp) words.push_back(temp);
    for_each(words.begin(), words.end(),
             bind(print, ref(cout),_1, ' '));
    cout << endl;
    for_each(words.begin(), words.end(),
             [](const string &s){ cout << s << ' '; });
    cout << endl;
    return 0;
}
