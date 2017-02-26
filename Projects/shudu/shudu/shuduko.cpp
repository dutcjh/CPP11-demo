#include <iostream>
#include <fstream>
#include <string>
#include "shudu.h"

using namespace std;

int main()
{
	fstream fin("sudu.txt", ios::in);
	Suduko sd(fin); // 定义有个数独类
	ofstream out("sudu.txt", ios::out);

	sd.display_sudu(); // 显示数独矩阵函数
	sd.prob_updates(); // 可能性矩阵更新函数
	sd.sudu_updates();  // 求解一次
	sd.sudu_save(out); // 保存计算结果

	sd.display_sudu(); // 显示数独矩阵函数
	sd.prob_updates(); // 可能性矩阵更新函数
	return 0;
}
