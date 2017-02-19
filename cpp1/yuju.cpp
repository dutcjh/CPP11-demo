#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    unsigned aCnt{0}, eCnt{0}, iCnt{0}, oCnt{0}, uCnt{0}, bCnt{0};
    char ch;
    while (cin >> ch)
    {
        switch (ch)
        {
            case 'a':
                ++aCnt;
                break;
            case 'e':
                ++eCnt;
                break;
            case 'i':
                ++iCnt;
                break;
            case 'o':
                ++oCnt;
                break;
            case 'u':
                ++uCnt;
                break;
            default:
                ++bCnt;
                break;
        }
    }

    cout << "Number of vowel a: " << aCnt << endl;
    cout << "Number of vowel e: " << eCnt << endl;
    cout << "Number of vowel i: " << iCnt << endl;
    cout << "Number of vowel o: " << oCnt << endl;
    cout << "Number of vowel u: " << uCnt << endl;
    cout << "Number of others : " << bCnt << endl;

    return 0;
}
