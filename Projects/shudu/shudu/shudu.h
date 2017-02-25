#ifndef __SHUDU_H__
#define __SHUDU_H__

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
	ofstream out("log.txt", ios::app);
	cout << "-------------------------------------" << endl;
	out << "-------------------------------------" << endl;
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < rnt; ++j)
		{
			if (arr[i][j] == 0)
			{
				cout << "| " << " " << " ";
				out << "| " << " " << " ";
			}	
			else
			{
				cout << "| " << arr[i][j] << " ";
				out << "| " << arr[i][j] << " ";
			}
		}
		cout << "|" << endl;
		cout << "-------------------------------------" << endl;
		out << "|" << endl;
		out << "-------------------------------------" << endl;
	}
	out.close();
}

#endif // __SHUDU_H__
