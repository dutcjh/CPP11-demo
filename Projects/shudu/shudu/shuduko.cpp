#include <iostream>
#include <vector>

using namespace std;

const unsigned cnt = 9;
const unsigned rnt = 9;
const unsigned qnt = 9;
const unsigned nnt = 9;

vector<unsigned> select(const unsigned(&arr)[cnt][rnt], 
					const unsigned(&qu)[qnt][nnt], 
					const unsigned c, const unsigned r, unsigned &num)
{
	vector<unsigned> s;
	if (arr[c][r] != 0)
	{
		s.push_back(0);
		num = 0;
	}
	else
	{
		unsigned snum[cnt] = {};
		for (int j = 0; j < rnt; ++j)
			if (arr[c][j])
				snum[arr[c][j] - 1] = 1;
		for (int i = 0; i < cnt; ++i)
			if (arr[i][r])
				snum[arr[i][r] - 1] = 1;
		const unsigned a = (c / 3) * 3 + r / 3;
		for (int k = 0; k < nnt; ++k)
			if (qu[a][k])
				snum[qu[a][k] - 1] = 1;
		for (int i = 0; i < cnt; ++i)
			if (!snum[i])
				s.push_back(i + 1);
		num = size(s);
	}
	return s;
}

void display(const unsigned(&arr)[cnt][rnt])
{
	cout << "-------------------------------------" << endl;
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < rnt; ++j)
		{
			if (arr[i][j] == 0)
				cout << "| " << " " << " ";
			else
				cout << "| " << arr[i][j] << " ";
		}
		cout << "|" << endl;
		cout << "-------------------------------------" << endl;
	}
}

int main()
{
	unsigned sudu[cnt][rnt] = {};
	unsigned quyu[qnt][nnt] = {};
	cout << "Please Enter origin number:" << endl;
	for (int i = 0; i < cnt; ++i)
		for (int j = 0; j < rnt; ++j)
		{
			cin >> sudu[i][j];
			quyu[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3] = sudu[i][j];		
		}			
	display(sudu);
/*	for (int i = 0; i < nnt; ++i)
	{
		cout << quyu[0][i] << " ";
	} */
	unsigned frequ[cnt][rnt] = {};
	unsigned num = 0;
	vector<unsigned> s = {};
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < rnt; ++j)
		{
			s = select(sudu, quyu, i, j, num);
			frequ[i][j] = num;
			if (num == 1)
			{
				cout << i+1 << "," << j+1 << "->";
				for (auto item : s)
					cout << item << endl;
			}
		}
	}
	cout << endl;
	display(frequ);
	return 0;
}