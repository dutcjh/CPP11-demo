#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s = "string";
    cout << s << endl;
    const char *str = s.c_str();
    for (decltype(s.size()) i = 0; i != s.size(); ++i)
        cout << *(str+i);
    cout << endl;
    int int_arr[] = {0,1,2,3,4,5};
    vector<int> ivec(begin(int_arr), end(int_arr));
    for (auto i : ivec)
        cout << i << " ";
    cout << endl;
    const vector<int> avec{1,2,3,4,5,6,7,8,9,0};
    for (auto a : avec)
        cout << a << " ";
    cout << endl;
    int arr[avec.size()];
    for (decltype(avec.size()) i = 0; i != avec.size(); ++i)
        arr[i] = avec[i];
    int *b = arr, *e = &arr[avec.size()];
    while (b < e)
    {
        cout << *b++ << " ";
    }
    return 0;
}
