#include<iostream>
using namespace std;

#define N 5

class Point{ //类的定义
public: //外部接口
	Point() : _x(0), _y(0) {};
	Point(int x, int y) : _x(x), _y(y) {};
	~Point() {};
	void setX(int x){ _x = x; }
	void setY(int y){ _y = y; }
	int getX() const { return _x; }
	int getY() const { return _y; }
private: //私有数据成员
	int _x, _y;
};

int main()
{
    Point p[N];
    for(int i = 0; i < N; ++i) // 给对象赋值
        p[i] = Point(i,i);
    for(int i = 0; i < N; ++i) // 输出对象
        cout << p[i].getX() << " " << p[i].getY() << endl;
    return 0;
}
