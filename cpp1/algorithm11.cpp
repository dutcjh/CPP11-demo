#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec)
{
    for(auto i : vec) os << i << " ";
    return os;
}

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    // cout << words.size() << ": " << words << endl;
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

int main()
{
    vector<string> words;
    // the quick red fox jumps over the slow red turtle
    string temp;
    while(cin >> temp) words.push_back(temp);
    cout << words.size() << ": " << words << endl;
    elimDups(words);
    cout << words.size() << ": " << words << endl;
    return 0;
}


