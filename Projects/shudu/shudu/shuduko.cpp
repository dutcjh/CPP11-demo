#include <iostream>
#include <fstream>
#include <vector>
#include "shudu.h"

using namespace std;

int main()
{
	unsigned sudu[cnt][rnt] = {};
	unsigned quyu[qnt][nnt] = {};
	fstream fin("sudu.txt", fstream::in);
	cout << "Please Enter origin number:" << endl;
	for (int i = 0; i < cnt; ++i)
		for (int j = 0; j < rnt; ++j)
		{
			fin >> sudu[i][j];
			quyu[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3] = sudu[i][j];		
		}	
	fin.close();
	display(sudu);
	unsigned frequ[cnt][rnt] = {};
	unsigned num = 0;
	ofstream out("log.txt", ios::app);
	ofstream upset("sudu.txt", ios::out);
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
				{
					cout << item << endl;
					upset << item << ' ';
				}	
			}
			else if (!num)
				upset << sudu[i][j] << ' ';
			else
				upset << "0 ";
			if (num)
			{
				out << num << " --> ";
				for (auto item : s)
					out << item << ',';
				out << endl;
			}
		}
		upset << endl;
	}
	upset.close();
	out << endl;
	out.close();
	cout << endl;
	display(frequ);
	
	return 0;
}
