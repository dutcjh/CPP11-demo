#include<iostream>

using namespace std;

void print(const char *cp)
{
    if(cp)
        while (*cp)
            cout << *cp++;
}
int main()
{
    char s[] = "Hello world!";
    print(s);
    cout << endl;
    return 0;
}
