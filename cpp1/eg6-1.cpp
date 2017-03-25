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
    void showCount() { cout << " Object count = " << count << endl; }
private:
    int x,y;
    static int count; // ��̬���ݳ�Ա���������ڼ�¼���������
};

int Point::count = 0; // ��̬���ݳ�Ա����ͳ�ʼ����ʹ�������޶�

int main()
{
    Point a(4,5);
    cout << "Point A: (" << a.getX() << ", " << a.getY() << ")";
    a.showCount();
    Point b(a);
    cout << "Point B: (" << b.getX() << ", " << b.getY() << ")";
    b.showCount();
    return 0;
}
