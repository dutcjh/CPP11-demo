#ifndef __SHUDU_H__
#define __SHUDU_H__

using namespace std;

const unsigned cnt = 9;
const unsigned rnt = 9;
const unsigned qnt = 9;
const unsigned nnt = 9;

class Suduko
{
public:
	unsigned sudu[cnt][rnt] = {};
private:
	unsigned quyu[qnt][nnt] = {};
	unsigned prob[cnt][rnt] = {};
	unsigned judge(const unsigned c, const unsigned r);
	unsigned qukuai(const unsigned c, const unsigned r);
	void prob_updates(); // �����Ծ�����º���
public:
	Suduko(){}           // ���캯��1
	Suduko(fstream &fin); // ���캯��
	Suduko(const unsigned arr[cnt][rnt]);	//���캯��2
	void sudu_read(fstream &fin);// ��ȡsudu����
	void display_sudu(); // ��ʾ����������
	void display_prob(); // ��ʾ�����Ծ�����
	void log_updates(ofstream &out);// ����log�ļ�����
	void sudu_updates();  // ���һ��
	void sudu_save(ofstream &out); // ���������
	int is_over(int pflag); // �ж��Ƿ����
	void quyu_update();  // ����quyu
	//void generator(Suduko &item, unsigned &c, unsigned &r, unsigned &num1, unsigned &num2); // ����һ�γ���
	Suduko operator=(const Suduko &items); // �ع����ں� =
};

// ���캯��1
Suduko::Suduko(fstream &fin) 
{
	sudu_read(fin);
	if (fin.is_open())
		fin.close();
}
//���캯��2
Suduko::Suduko(const unsigned arr[cnt][rnt])
{
	for (int i = 0; i < cnt; ++i)
		for (int j = 0; j < rnt; ++j)
		{
			sudu[i][j] = arr[i][j]; 
			quyu[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3] = sudu[i][j];
		}
}

inline void Suduko::quyu_update()
{
	for (int i = 0; i < cnt; ++i)
		for (int j = 0; j < rnt; ++j)
		{
			quyu[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3] = sudu[i][j];
		}
}

// ����һ�γ���
/*inline void Suduko::generator(Suduko &item, unsigned &c, unsigned &r, unsigned &num1, unsigned &num2)
{
	item = *this;
	unsigned count = 0;
	for (unsigned i = 0; i < cnt; ++i)
		for (unsigned j = 0; j < cnt; ++j)
		{
			count = 0;
			if (!sudu[i][j])
			{
				for (unsigned k = 0; k < cnt; ++k)
				{
					if ((prob[i][j] >> k) & 0x1)
					{
						++count;
					}
				}
				if (count == 2)
				{
					unsigned arr[2] = {};
					for (unsigned n = 0, k = 0; k < cnt; ++k)
					{
						if ((prob[i][j] >> k) & 0x1)
						{
							arr[n] = k + 1;
							++n;
						}
					}
					c = i;
					r = j;
					num1 = arr[0];
					num2 = arr[1];
					return;
				}
			}
		}
}*/

// �ع����ں� =
Suduko Suduko::operator=(const Suduko &items)
{
	Suduko items1(items.sudu);
	return items1;
}

bool operator==(const Suduko &items1, const Suduko &items2)
{
	for (unsigned i = 0; i < cnt; ++i)
		for (unsigned j = 0; j < rnt; ++j)
			if (items1.sudu[i][j] != items1.sudu[i][j])
				return false;
	return true;
}

bool operator!=(const Suduko &items1, const Suduko &items2)
{
	if (items1 == items2)
		return false;
	else
		return true;
}

ostream &operator<<(ostream &os, const Suduko &item)
{
	os << "-------------------------------------" << endl;
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < rnt; ++j)
		{
			if (item.sudu[i][j] == 0)
				os << "| " << " " << " ";
			else
				os << "| " << item.sudu[i][j] << " ";
		}
		os << "|" << endl;
		os << "-------------------------------------" << endl;
	}
	return os;
}

// �ж��Ƿ����
inline int Suduko::is_over(int pflag)
{
	int flag = 0, num = 0;
	unsigned temp = 0;
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < rnt; ++j)
		{
			if (!sudu[i][j])  // û�����
				++num;
			else // ���˵Ŀ��Ƿ��г�ͻ
			{
				for (unsigned k = 0; k < rnt; ++k)
				{ // �г�ͻ
					if (k == i)
						continue;
					if (sudu[k][j] == sudu[i][j])
						temp = 1;
				}
				for (unsigned k = 0; k < rnt; ++k)
				{ // �г�ͻ
					if (k == j)
						continue;
					if (sudu[i][k] == sudu[i][j])
						temp = 2;
				}
			}
		}
	}
	if (temp) // ������˵�
	{
		flag = -1;
	}
	else // û������˵�
	{
		if (num == 0) //��������û�д���
			flag = 0;
		else   // û������
		{
			if (num == pflag) // ��û�н�չ��ԭ��̤��
				flag = -2;
			else
				flag = num;
		}
	}
	return flag;
}

// ��ȡsudu����
inline void Suduko::sudu_read(fstream &fin)
{
	for (int i = 0; i < cnt; ++i)
		for (int j = 0; j < rnt; ++j)
		{
			fin >> sudu[i][j]; // ���ļ��ж�ȡ�������� ����������� 
			quyu[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3] = sudu[i][j];
		}
	if (fin.is_open())
		fin.close();
}

// ���һ��
inline void Suduko::sudu_updates()
{
	prob_updates();
	for (unsigned i = 0; i < cnt; ++i)
		for (unsigned j = 0; j < rnt; ++j)
		{
			sudu[i][j] = judge(i, j);
			quyu[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3] = sudu[i][j];
		}
}

// ���������
inline void Suduko::sudu_save(ofstream &out)
{
	for (unsigned i = 0; i < cnt; ++i)
	{
		for (unsigned j = 0; j < rnt; ++j)
		{
			out << sudu[i][j] << ' ';
		}
		out << endl;
	}
	if (out.is_open())
		out.close();
}

// �����Ծ�����º���
inline void Suduko::prob_updates()
{
	prob[cnt][rnt] = {};
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < rnt; ++j)
		{
			if (sudu[i][j])
				prob[i][j] = 0;
			else
			{   // �ж�������
				for (int k = 0; k < nnt; ++k)
					if (sudu[i][k])
						prob[i][j] |= (1 << (sudu[i][k] - 1));
				// �ж�������
				for (int p = 0; p < cnt; ++p)
					if (sudu[p][j])
						prob[i][j] |= (1 << (sudu[p][j] - 1));
				// �ж���������
				const unsigned a = (i / 3) * 3 + j / 3;
				for (int k = 0; k < nnt; ++k)
					if (quyu[a][k])
						prob[i][j] |= (1 << (quyu[a][k] - 1));
				prob[i][j] ^= 0x1FF;
			}
		}
	}
}


// ��ʾ��������
inline void Suduko::display_sudu()
{
	cout << "-------------------------------------" << endl;
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < rnt; ++j)
		{
			if (sudu[i][j] == 0)
				cout << "| " << " " << " ";
			else
				cout << "| " << sudu[i][j] << " ";
		}
		cout << "|" << endl;
		cout << "-------------------------------------" << endl;
	}
}

inline void Suduko::display_prob()
{
	cout << "=======================================================" << endl;
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < rnt; ++j)
		{
			if (prob[i][j] == 0)
				cout << "| " << " " << " ";
			else
				cout << "| " << prob[i][j] << " ";
		}
		cout << "|" << endl;
		cout << "=======================================================" << endl;
	}
}

// дlog�ļ�����
inline void Suduko::log_updates(ofstream &out)
{
	out << "-------------------------------------" << endl;
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < rnt; ++j)
		{
			if (sudu[i][j] == 0)
				out << "| " << " " << " ";
			else
				out << "| " << sudu[i][j] << " ";
		}
		out << "|" << endl;
		out << "-------------------------------------" << endl;
	}
	out << "=======================================================" << endl;
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < rnt; ++j)
		{
			if (prob[i][j] == 0)
				out << "| " << "   " << " ";
			else
				out << "| " << prob[i][j] << " ";
		}
		out << "|" << endl;
		out << "=======================================================" << endl;
	}
	out << endl;
	if (out.is_open())
		out.close();
}

inline unsigned Suduko::judge(const unsigned c, const unsigned r)
{
	unsigned a = 0, acc = 0;
	if (sudu[c][r]) // ԭ���ĸ�������ȷ��������
		return sudu[c][r];
	else // ԭ���ĸ����ǿո�
	{
		for (unsigned i = 0; i < nnt; ++i)
		{
			if ((prob[c][r] >> i) & 0x1)
			{ // �жϿ��ܵ�����
				++acc;
				a = i + 1;
			}
		}
		if (acc == 1) // ֻҪһ�����ܵ���
			return a;
		else // ��ֹһ�����ܵ���
		{
			unsigned temp = 0;
			// ������
			for (unsigned i = 0; i < rnt; ++i)
			{
				if (i == r)
					continue;
				temp |= prob[c][i];
			}
			for (unsigned i = 0; i < nnt; ++i)
			{// �ж���������ܵ�����
				if (((prob[c][r] >> i) & 0x1) && !((temp >> i) & 0x1))
					return (i + 1);
			}

			temp = 0; // ������
			for (unsigned i = 0; i < cnt; ++i)
			{
				if (i == c)
					continue;
				temp |= prob[i][r];
			}
			for (unsigned i = 0; i < nnt; ++i)
			{// �ж���������ܵ�����
				if (((prob[c][r] >> i) & 0x1) && !((temp >> i) & 0x1))
					return (i + 1);
			}

			temp = 0; // ��������
			temp |= qukuai(c, r);
			for (unsigned i = 0; i < nnt; ++i)
			{// �жϿ��ܵ�����
				if (((prob[c][r] >> i) & 0x1) && !((temp >> i) & 0x1))
					return (i + 1);
			}
			return 0;
		}
	}
}

// ���������ۼ�ֵ
unsigned Suduko::qukuai(const unsigned c, const unsigned r)
{
	unsigned temp = 0;
	unsigned p = c % 3, q = r % 3;
	unsigned c1, c2, r1, r2;
	if (p == 0)
	{
		c1 = c + 1;
		c2 = c + 2;
	}
	else if (p == 1)
	{
		c1 = c - 1;
		c2 = c + 1;
	}
	else
	{
		c1 = c - 2;
		c2 = c - 1;
	}
	if (q == 0)
	{
		r1 = r + 1;
		r2 = r + 2;
	}
	else if (q == 1)
	{
		r1 = r - 1;
		r2 = r + 1;
	}
	else
	{
		r1 = r - 2;
		r2 = r - 1;
	}
	temp = prob[c1][r1] | prob[c1][r2] | prob[c2][r1] | prob[c2][r2] |
		prob[c][r1] | prob[c][r2] | prob[c1][r] | prob[c2][r];
	return temp;
}

#endif // __SHUDU_H__
