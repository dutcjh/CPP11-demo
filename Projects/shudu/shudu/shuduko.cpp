#include <iostream>
#include <fstream>
#include <string>
#include "shudu.h"

using namespace std;

int main()
{
	fstream fin("sudu.txt", ios::in);
	Suduko sd(fin); // �����и�������
	ofstream out("sudu.txt", ios::out);

	sd.display_sudu(); // ��ʾ����������
	sd.prob_updates(); // �����Ծ�����º���
	sd.sudu_updates();  // ���һ��
	sd.sudu_save(out); // ���������

	sd.display_sudu(); // ��ʾ����������
	sd.prob_updates(); // �����Ծ�����º���
	return 0;
}
