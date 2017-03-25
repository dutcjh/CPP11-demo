#include<iostream>
using namespace std;
class Point
{
public:
    Point(int x = 0, int y = 0) : x(x), y(y){ count++; }
    Point(Point &p){ x = p.x; y = p.y; count++; }
    ~Point() { count--; }
    int getX() const { return x; }
    int getY() const { return y; }
    static void showCount() // 静态成员函数
        { cout << " Object count = " << count << endl; }
private:
    int x,y;
    static int count; // 静态数据成员声明，用于记录点个个数。
};

int Point::count = 0; // 静态数据成员定义和初始化，使用类名限定

int main()
{
    Point a(4,5);
    cout << "Point A: (" << a.getX() << ", " << a.getY() << ")";
    Point::showCount();
    Point b(a);
    cout << "Point B: (" << b.getX() << ", " << b.getY() << ")";
    Point::showCount();
    return 0;
}

