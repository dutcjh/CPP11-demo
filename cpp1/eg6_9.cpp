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
    friend float dist(const Point &p1, const Point &p2);
private:
    int x,y;
};

float dist(const Point &p1, const Point &p2)
{
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    return static_cast<float> (sqrt(x*x + y*y));
}

int main()
{
    const Point p1(1,1), p2(4,5);
    cout << "The distance is: " << dist(p1, p2) << endl;
    return 0;
}

