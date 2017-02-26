#include <iostream>
#include <fstream>
#include <string>
#include "shudu.h"

using namespace std;

int main()
{
	int flag = 0;
	fstream fin("sudu.txt", ios::in);
	Suduko sd(fin); // 定义一个数独类
	flag = sd.is_over(flag);  // 判断是否结束
	cout << flag << "\n" << sd << endl; // 显示
	while (flag) // 0结束，非0没有结束
	{
		if (flag == -2) // 算不下去了
		{
			cout << "算不下去了！" << endl;
			break;
		}
		else if (flag == -1) // 出错了
		{
			cout << "出错了！" << endl;
			break;
		}
		else // 没有结束
		{
			sd.sudu_updates();  // 求解一次
			sd.sudu_updates();  // 求解一次
			ofstream out("sudu.txt", ios::out);
			sd.sudu_save(out);
			flag = sd.is_over(flag);  // 判断是否结束
			cout << flag << "\n" << sd << endl; // 显示
		}
	}
	return 0;
}
