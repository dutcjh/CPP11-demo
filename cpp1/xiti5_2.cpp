#include <iostream>
using namespace std;
const double PI = 3.1415926; // ���峣��PI

class Circle
{
private:
    double r; // �뾶
public:
    Circle():r(0){} //���������Ĺ��캯��
    Circle(const double &x):r(x){} // �������Ĺ��캯��
    Circle(const Circle &c):r(c.r){} //�������캯��
    void set_radius(const double &x) { r = x; } //���ð뾶
    double get_area() const { return r*r*PI; } //�������
    double get_perimeter() const { return 2*r*PI; } // �����ܳ�
};

int main()
{
    Circle c1; // ����һ��Բ����c1
    double x;
    do{
        cout << "Please input the circle radius: x = ";
        cin >> x; // �Ӽ�������һ��ֵx
    }while(x<0);
    c1.set_radius(x); // ���趨Ϊc1�İ뾶
    // ���㲢��ʾc1��������ܳ�
    cout << "The circle c1: \n" << "Area: " << c1.get_area()
        << "\nPerimeter: " << c1.get_perimeter() << endl;
    Circle c2(2*x); // ����һ��Բ����c2�������뾶��ʼ��Ϊ2x
    // ���㲢��ʾc2��������ܳ�
    cout << "The circle c2: \n" << "Area: " << c2.get_area()
        << "\nPerimeter: " << c2.get_perimeter() << endl;
    Circle c3(c1); // ����һ��Բ����c3������c1��ʼ��c3
    // ���㲢��ʾc3��������ܳ�
    cout << "The circle c3: \n" << "Area: " << c3.get_area()
        << "\nPerimeter: " << c3.get_perimeter() << endl;
    return 0;
}
