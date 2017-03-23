#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
using namespace std::placeholders;

template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec)
{
    for_each(vec.cbegin(), vec.cend(),
             [&os](const T &s){ os << s << " "; });
    // for(const auto &i : vec) os << i << " ";
    return os;
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    vector<string> words;
    // the quick red fox jumps over the slow red turtle
    string temp;
    while(cin >> temp) words.push_back(temp);
    sort(words.begin(), words.end(), isShorter);
    cout << words << endl;
    sort(words.begin(), words.end(), bind(isShorter,_2,_1));
    cout << words << endl;
    return 0;
}
