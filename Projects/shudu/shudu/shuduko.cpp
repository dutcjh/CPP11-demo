#include <iostream>
#include <fstream>
#include <string>
#include "shudu.h"

using namespace std;

int main()
{
	int flag = 0;
	fstream fin("sudu.txt", ios::in);
	Suduko sd(fin); // ����һ��������
	flag = sd.is_over(flag);  // �ж��Ƿ����
	cout << flag << "\n" << sd << endl; // ��ʾ
	while (flag) // 0��������0û�н���
	{
		if (flag == -2) // �㲻��ȥ��
		{
			cout << "�㲻��ȥ�ˣ�" << endl;
			break;
		}
		else if (flag == -1) // ������
		{
			cout << "�����ˣ�" << endl;
			break;
		}
		else // û�н���
		{
			sd.sudu_updates();  // ���һ��
			sd.sudu_updates();  // ���һ��
			ofstream out("sudu.txt", ios::out);
			sd.sudu_save(out);
			flag = sd.is_over(flag);  // �ж��Ƿ����
			cout << flag << "\n" << sd << endl; // ��ʾ
		}
	}
	return 0;
}
