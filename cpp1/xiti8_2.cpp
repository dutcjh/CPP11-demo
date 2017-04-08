#include<iostream>
using namespace std;

class vehicle //汽车类vehicle
{
private:
    unsigned wheels; //车轮个数
    double weight;   //车重
public:
    vehicle(unsigned wheels, double weight):
        wheels(wheels), weight(weight){}
    void display() //输出函数
    {
        cout << "wheels: " << wheels << endl;
        cout << "weight: " << weight << endl;
    }
};

class car : private vehicle //派生类car，继承vehicle
{
private:
    unsigned passengers; //载人数
public:
    car(unsigned wheels, double weight, unsigned passengers):
        vehicle(wheels, weight), passengers(passengers){}
    void display() //输出函数
    {
        vehicle::display();
        cout << "passengers: " << passengers << endl;
    }
};

class truck : private vehicle //派生类truck，继承vehicle
{
private:
    unsigned passengers; //载人数
    double payload;  //载重量
public:
    truck(unsigned wheels, double weight, unsigned passengers,
          double payload): vehicle(wheels, weight),
          passengers(passengers), payload(payload){}
    void display() //输出函数
    {
        vehicle::display();
        cout << "passengers: " << passengers << endl;
        cout << "payload: " << payload << endl;
    }
};

int main()
{
	vehicle obj1(4,4);
	cout<<"vehicle information:"<<endl;
	obj1.display ();
	car obj2(4,2,5);
	cout<<endl<<"car information:"<<endl;
	obj2.display();
	truck obj3(8,6,2,20);
	cout<<endl<<"truck information:"<<endl;
	obj3.display ();
	return 0;
}
