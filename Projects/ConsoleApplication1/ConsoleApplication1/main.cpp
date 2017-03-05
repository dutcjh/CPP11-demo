#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

struct DNA
{
	string s;
	unsigned value;
};

int cmp(const DNA *a, const DNA *b) { return (a->value - b->value); }

unsigned get_nixu(const string &s)
{
	unsigned num = 0;
	for (unsigned i = 0; i < s.length() - 1; ++i)
		for (unsigned j = i + 1; j < s.length(); ++j)
			if (s[i] > s[j]) num++;
	return num;
}

int main()
{
	unsigned L, N;
	cin >> L >> N;
	DNA *xulie = new DNA[N];
	for (unsigned i = 0; i<N; ++i)
	{
		cin >> (xulie + i)->s;
		(xulie + i)->value = get_nixu((xulie + i)->s);
	}
	qsort(xulie, N, sizeof(DNA), (int(*)(const void *, const void*))cmp);
	for (unsigned i = 0; i<N; ++i)
		cout << (xulie + i)->s << endl;
	delete[] xulie;
	return 0;
}
