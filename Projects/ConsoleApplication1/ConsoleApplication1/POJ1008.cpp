#include<iostream>
#include<string>
using namespace std;

const string Haab[19] = { "pop","no","zip","zotz","tzec",\
"xul","yoxkin","mol","chen","yax","zac","ceh","mac",\
"kankin","muan","pax","koyab","cumhu","uayet" };
const string Tzolkin[20] = { "imix","ik","akbal","kan","chicchan",\
"cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix",\
"mem","cib","caban","eznab","canac","ahau" };

int main()
{
	int n;
	cin >> n;
	cout << n << endl;
	for (int i = 0; i<n; ++i)
	{
		int year, day;
		char a;
		string month;
		cin >> day >> a >> month >> year;
		int j;
		for (j = 0; j<19; ++j)
			if (month == Haab[j])
				break;
		int total = day + j * 20 + year * 365;
		int d, y, m;
		d = total % 13 + 1;
		m = total % 20;
		y = total / 260;
		cout << d << ' ' << Tzolkin[m] << ' ' << y << endl;
	}
	return 0;
}
