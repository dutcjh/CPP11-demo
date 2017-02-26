#ifndef __SHUDU_H__
#define __SHUDU_H__

using namespace std;

const unsigned cnt = 9;
const unsigned rnt = 9;
const unsigned qnt = 9;
const unsigned nnt = 9;

class Suduko
{
private:
	unsigned sudu[cnt][rnt] = {};
	unsigned quyu[qnt][nnt] = {};
	unsigned prob[cnt][rnt] = {};
	unsigned judge(const unsigned c, const unsigned r);
	unsigned qukuai(const unsigned c, const unsigned r);
public:
	Suduko(fstream &fin); // ���캯��
	void sudu_read(fstream &fin);// ��ȡsudu����
	void prob_updates(); // �����Ծ�����º���
	void display_sudu(); // ��ʾ����������
	void display_prob(); // ��ʾ�����Ծ�����
	void log_updates(ofstream &out);// ����log�ļ�����
	void sudu_updates();  // ���һ��
	void sudu_save(ofstream &out); // ���������
	bool is_over(); // �ж��Ƿ����
};

// ���캯��
Suduko::Suduko(fstream &fin) 
{
	sudu_read(fin);
	if (fin.is_open())
		fin.close();
}

// �ж��Ƿ����
inline bool Suduko::is_over()
{
	for (int i = 0; i < cnt; ++i)
		for (int j = 0; j < rnt; ++j)
			if (!sudu[i][j])
				return false;
	return true;
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
	for (unsigned i = 0; i < cnt; ++i)
		for (unsigned j = 0; j < cnt; ++j)
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
