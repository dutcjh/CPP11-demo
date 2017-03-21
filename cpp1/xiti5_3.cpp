#include <iostream>
using namespace std;

class Cuboid
{
private:
    double length, width, height;
public:
    Cuboid(const double l=0, const double w=0, const double h=0):
        length(l), width(w), height(h){}
    Cuboid(const Cuboid &c):
        length(c.length), width(c.width), height(c.height){}
    double get_volume() const { return length*width*height; } // 计算体积
    double get_sufarea() const // 计算表面积
        { return 2*(length*width+length*height+width*height); }
    void set_value(const double &l, const double &w, const double &h)
        { length = l; width = w; height = h; } // 参数设置
    friend ostream &operator<<(ostream &os, const Cuboid &c); // 重载输出<<
};

ostream &operator<<(ostream &os, const Cuboid &c)
{
    os << "Length: " << c.length << "\tWidth: " << c.width
    << "\tHeight: " << c.height << "\nVolume: " << c.get_volume()
    << "\nSurface area: " << c.get_sufarea();
    return os;
}

int main()
{
    Cuboid cub1; // 定义一个长方体对象cub1
    double x,y,z;
    do{
        cout << "Please input length, width and height(eg:1 2 3): ";
        cin >> x >> y >> z; // 从键盘输入值x,y,z
    }while(x<0||y<0||z<0);
    cub1.set_value(x,y,z);
    cout << "The cuboid cub1: \n" << cub1 << endl;// 计算并显示cub1的体积和表面积
    Cuboid cub2(cub1);
    cout << "The cuboid cub2: \n" << cub2 << endl;// 计算并显示cub2的体积和表面积
    Cuboid cub3(2*x, 2*y, 2*z);
    cout << "The cuboid cub3: \n" << cub3 << endl;// 计算并显示cub3的体积和表面积
    Cuboid cub4(1,1,1);
    cout << "The cuboid cub4: \n" << cub4 << endl;// 计算并显示cub4的体积和表面积
    return 0;
}
