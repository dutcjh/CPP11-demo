#include<iostream>
using namespace std;

class vehicle //������vehicle
{
private:
    unsigned wheels; //���ָ���
    double weight;   //����
public:
    vehicle(unsigned wheels, double weight):
        wheels(wheels), weight(weight){}
    void display() //�������
    {
        cout << "wheels: " << wheels << endl;
        cout << "weight: " << weight << endl;
    }
};

class car : private vehicle //������car���̳�vehicle
{
private:
    unsigned passengers; //������
public:
    car(unsigned wheels, double weight, unsigned passengers):
        vehicle(wheels, weight), passengers(passengers){}
    void display() //�������
    {
        vehicle::display();
        cout << "passengers: " << passengers << endl;
    }
};

class truck : private vehicle //������truck���̳�vehicle
{
private:
    unsigned passengers; //������
    double payload;  //������
public:
    truck(unsigned wheels, double weight, unsigned passengers,
          double payload): vehicle(wheels, weight),
          passengers(passengers), payload(payload){}
    void display() //�������
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
