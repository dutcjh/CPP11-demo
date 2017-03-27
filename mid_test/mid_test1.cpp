#include<iostream>
using namespace std;

int main()
{
    char letter;
    cout << "Please input a letter: ";
    cin >> letter;
    if ((letter > 'A' && letter < 'Z')||(letter > 'a' && letter < 'z'))
        cout << char(letter-1) << letter << char(letter+1) << endl;
    else if ((letter == 'A')||(letter == 'a'))
        cout << char(letter+25) << letter << char(letter+1) << endl;
    else if ((letter == 'Z')||(letter == 'z'))
        cout << char(letter-1) << letter << char(letter-25) << endl;
    else
        cout << "ERROR INPUT!!!" << endl;
    return 0;
}
