#include<iostream>
using namespace std;

class Circle  // 圆形类：声明部分，即声明成员
{
public:
	double CRadius();  // 读取半径：公有函数成员
	double CArea();    // 求面积：公有函数成员
	Circle(double x);  // 有参构造函数：公有权限
private:
    double r;  // 半径：保护数据成员
};

class Ring:public Circle{
public:
	Ring(double x, double y) :Circle(x){
		w = y;
	}
	double RArea(); //求圆环面积
private:
	double w;
};

int main(){
	Ring obj(5, 3);
	cout << obj.RArea() << endl;
    return 0;
}

const double PI = 3.1415926;

// 读取半径：公有函数成员
double Circle::CRadius() { return r; }

// 求面积：公有函数成员
double Circle::CArea() { return PI*r*r; }

// 有参构造函数：公有权限
Circle::Circle(double x): r(x){}

//求圆环面积
double Ring::RArea()
{
    Circle cw(CRadius()+w); // 定义一个圆环的外圆对象
    return cw.CArea() - CArea();
}
