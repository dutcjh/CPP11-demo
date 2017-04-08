#include<iostream>
using namespace std;

class Circle  // Բ���ࣺ�������֣���������Ա
{
public:
	double CRadius();  // ��ȡ�뾶�����к�����Ա
	double CArea();    // ����������к�����Ա
	Circle(double x);  // �вι��캯��������Ȩ��
private:
    double r;  // �뾶���������ݳ�Ա
};

class Ring:public Circle{
public:
	Ring(double x, double y) :Circle(x){
		w = y;
	}
	double RArea(); //��Բ�����
private:
	double w;
};

int main(){
	Ring obj(5, 3);
	cout << obj.RArea() << endl;
    return 0;
}

const double PI = 3.1415926;

// ��ȡ�뾶�����к�����Ա
double Circle::CRadius() { return r; }

// ����������к�����Ա
double Circle::CArea() { return PI*r*r; }

// �вι��캯��������Ȩ��
Circle::Circle(double x): r(x){}

//��Բ�����
double Ring::RArea()
{
    Circle cw(CRadius()+w); // ����һ��Բ������Բ����
    return cw.CArea() - CArea();
}
