#include<iostream>
using namespace std;

class Building //基类Building
{
private:
    unsigned Floors, Rooms;
    double Area;
public:
    Building(unsigned floors, unsigned rooms, double area):
        Floors(floors), Rooms(rooms), Area(area){}
    void DisplayBuilding() //相应的输出函数
    {
        cout << "Floors: " << Floors << endl;
        cout << "Rooms: " << Rooms << endl;
        cout << "Area: " << Area << endl;
    }
};

class House : public Building //派生类House，继承Building
{
private:
    unsigned Bedrooms, Washrooms;
public:
    House(unsigned floors, unsigned rooms, double area,
          unsigned bedrooms, unsigned washrooms):
        Building(floors, rooms, area),
        Bedrooms(bedrooms), Washrooms(washrooms){}
    void DisplayHouse() //相应的输出函数
    {
        DisplayBuilding();
        cout << "Bedrooms: " << Bedrooms << endl;
        cout << "Washrooms: " << Washrooms << endl;
    }
};

class Office : public Building //派生类Office，继承Building
{
private:
    unsigned Extinguishers, Telephones;
public:
    Office(unsigned floors, unsigned rooms, double area,
          unsigned extinguishers, unsigned telephones):
        Building(floors, rooms, area),
        Extinguishers(extinguishers), Telephones(telephones){}
    void DisplayOffice() //相应的输出函数
    {
        DisplayBuilding();
        cout << "Extinguishers: " << Extinguishers << endl;
        cout << "Telephones: " << Telephones << endl;
    }
};

int main() //主函数
{
	Building obj1(15,200,50000);
	cout<<"Building:"<<endl;
	obj1.DisplayBuilding();
	House obj2(6,36,1000,24,12);
	cout<<endl<<"House:"<<endl;
	obj2.DisplayHouse();
	Office obj3(12,100,5000,24,100);
	cout<<endl<<"Office:"<<endl;
	obj3.DisplayOffice();
	return 0;
}
