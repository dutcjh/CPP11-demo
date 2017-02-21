#include <iostream>
#include "area.h"

using namespace std;

int main()
{
	Circle obj1;
	Rectangle obj2;
	cin >> obj1.r >> obj2.a >> obj2.b;
	cout << obj1.CArea() << endl;
	cout << obj1.CLen() << endl;
	cout << obj2.RArea() << endl;
	cout << obj2.RLen() << endl;
	return 0;
}