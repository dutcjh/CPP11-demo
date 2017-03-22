#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    // cout << words.size() << ": " << words << endl;
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(),
                [](const string &a, const string &b)
                {return a.size() < b.size();});
    auto wc = find_if(words.begin(), words.end(),
                      [=](const string &a){return a.size()>=sz;});
    auto count = words.end() - wc;
    cout << count << " " << [](size_t ctr, const string &word, const string &ending)
                { return (ctr > 1)?word+ending:word; }(count, "word", "s")
                << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(), [](const string &s){ cout << s << " ";});
    cout << endl;
}

int main()
{
    vector<string> words;
    // the quick red fox jumps over the slow red turtle
    string temp;
    while(cin >> temp) words.push_back(temp);
    biggies(words, 5);
    return 0;
}
