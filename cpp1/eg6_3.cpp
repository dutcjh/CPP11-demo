#include<iostream>
#include<string>
using namespace std;

enum color{ YELLOW, WHITE, BLACK, BROWN };

class Chinese
{
public:
    static color getSkinColor(Chinese Person) // ¾²Ì¬º¯Êý³ÉÔ±
    {
        cout << Person.Name << endl;
        cout << SkinColor << endl;
        return SkinColor;
    }
    Chinese (string s) : Name(s) {}
    ~Chinese() = default;
    void ShowMessage()
    {
        cout << Name << endl;
        cout << SkinColor << endl;
    }
private:
    static color SkinColor;
    string Name;
};
color Chinese::SkinColor = YELLOW;

int main()
{
    Chinese Li("Liming");
    Chinese::getSkinColor(Li);
    Li.ShowMessage();
    return 0;
}
