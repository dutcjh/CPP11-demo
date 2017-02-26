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
	Suduko(fstream &fin); // 构造函数
	void sudu_read(fstream &fin);// 读取sudu矩阵
	void prob_updates(); // 可能性矩阵更新函数
	void display_sudu(); // 显示数独矩阵函数
	void display_prob(); // 显示可能性矩阵函数
	void log_updates(ofstream &out);// 更新log文件函数
	void sudu_updates();  // 求解一次
	void sudu_save(ofstream &out); // 保存计算结果
	bool is_over(); // 判断是否结束
};

// 构造函数
Suduko::Suduko(fstream &fin) 
{
	sudu_read(fin);
	if (fin.is_open())
		fin.close();
}

// 判断是否结束
inline bool Suduko::is_over()
{
	for (int i = 0; i < cnt; ++i)
		for (int j = 0; j < rnt; ++j)
			if (!sudu[i][j])
				return false;
	return true;
}

// 读取sudu矩阵
inline void Suduko::sudu_read(fstream &fin)
{
	for (int i = 0; i < cnt; ++i)
		for (int j = 0; j < rnt; ++j)
		{
			fin >> sudu[i][j]; // 从文件中读取数独矩阵 生成区域矩阵 
			quyu[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3] = sudu[i][j];
		}
	if (fin.is_open())
		fin.close();
}

// 求解一次
inline void Suduko::sudu_updates()
{
	for (unsigned i = 0; i < cnt; ++i)
		for (unsigned j = 0; j < cnt; ++j)
		{
			sudu[i][j] = judge(i, j);
			quyu[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3] = sudu[i][j];
		}
}

// 保存计算结果
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

// 可能性矩阵更新函数
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
			{   // 判断行数字
				for (int k = 0; k < nnt; ++k)
					if (sudu[i][k])
						prob[i][j] |= (1 << (sudu[i][k] - 1));
				// 判断列数字
				for (int p = 0; p < cnt; ++p)
					if (sudu[p][j])
						prob[i][j] |= (1 << (sudu[p][j] - 1));
				// 判断区域数字
				const unsigned a = (i / 3) * 3 + j / 3;
				for (int k = 0; k < nnt; ++k)
					if (quyu[a][k])
						prob[i][j] |= (1 << (quyu[a][k] - 1));
				prob[i][j] ^= 0x1FF;
			}
		}
	}
}


// 显示数独矩阵
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

// 写log文件函数
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
	if (sudu[c][r]) // 原来的格子中有确定的数字
		return sudu[c][r];
	else // 原来的格子是空格
	{
		for (unsigned i = 0; i < nnt; ++i)
		{
			if ((prob[c][r] >> i) & 0x1)
			{ // 判断可能的填数
				++acc;
				a = i + 1;
			}
		}
		if (acc == 1) // 只要一个可能的数
			return a;
		else // 不止一个可能的数
		{
			unsigned temp = 0;
			// 行区域
			for (unsigned i = 0; i < rnt; ++i)
			{
				if (i == r)
					continue;
				temp |= prob[c][i];
			}
			for (unsigned i = 0; i < nnt; ++i)
			{// 判断行区域可能的填数
				if (((prob[c][r] >> i) & 0x1) && !((temp >> i) & 0x1))
					return (i + 1);
			}

			temp = 0; // 列区域
			for (unsigned i = 0; i < cnt; ++i)
			{
				if (i == c)
					continue;
				temp |= prob[i][r];
			}
			for (unsigned i = 0; i < nnt; ++i)
			{// 判断列区域可能的填数
				if (((prob[c][r] >> i) & 0x1) && !((temp >> i) & 0x1))
					return (i + 1);
			}

			temp = 0; // 区块数据
			temp |= qukuai(c, r);
			for (unsigned i = 0; i < nnt; ++i)
			{// 判断可能的填数
				if (((prob[c][r] >> i) & 0x1) && !((temp >> i) & 0x1))
					return (i + 1);
			}
			return 0;
		}
	}
}

// 返回区块累计值
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
