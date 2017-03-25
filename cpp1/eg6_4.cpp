#include<iostream>
#include<cmath>
using namespace std;

class Point
{
public:
    Point(int x = 0, int y = 0) : x(x), y(y){ }
    Point(Point &p){ x = p.x; y = p.y; }
    ~Point() = default;
    int getX() const { return x; }
    int getY() const { return y; }
    friend float dist(Point &a, Point &b);
private:
    int x,y;
};

float dist(Point &a, Point &b)
{
    double x = a.x - b.x;
    double y = a.y - b.y;
    return static_cast<float> (sqrt(x*x + y*y));
}

int main()
{
    Point p1(1,1), p2(4,5);
    cout << "The distance is: " << dist(p1, p2) << endl;
    return 0;
}
