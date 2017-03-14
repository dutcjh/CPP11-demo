#include <iostream>
using namespace std;
const double PI = 3.1415926; // 定义常量PI

class Circle
{
private:
    double r; // 半径
public:
    Circle():r(0){} //不带参数的构造函数
    Circle(const double &x):r(x){} // 带参数的构造函数
    Circle(const Circle &c):r(c.r){} //拷贝构造函数
    void set_radius(const double &x) { r = x; } //设置半径
    double get_area() const { return r*r*PI; } //计算面积
    double get_perimeter() const { return 2*r*PI; } // 计算周长
};

int main()
{
    Circle c1; // 定义一个圆对象c1
    double x;
    do{
        cout << "Please input the circle radius: x = ";
        cin >> x; // 从键盘输入一个值x
    }while(x<0);
    c1.set_radius(x); // 其设定为c1的半径
    // 计算并显示c1的面积和周长
    cout << "The circle c1: \n" << "Area: " << c1.get_area()
        << "\nPerimeter: " << c1.get_perimeter() << endl;
    Circle c2(2*x); // 定义一个圆对象c2，并将半径初始化为2x
    // 计算并显示c2的面积和周长
    cout << "The circle c2: \n" << "Area: " << c2.get_area()
        << "\nPerimeter: " << c2.get_perimeter() << endl;
    Circle c3(c1); // 定义一个圆对象c3，并用c1初始化c3
    // 计算并显示c3的面积和周长
    cout << "The circle c3: \n" << "Area: " << c3.get_area()
        << "\nPerimeter: " << c3.get_perimeter() << endl;
    return 0;
}
