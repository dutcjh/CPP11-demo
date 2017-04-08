#include<iostream>
using namespace std;

class Building //����Building
{
private:
    unsigned Floors, Rooms;
    double Area;
public:
    Building(unsigned floors, unsigned rooms, double area):
        Floors(floors), Rooms(rooms), Area(area){}
    void DisplayBuilding() //��Ӧ���������
    {
        cout << "Floors: " << Floors << endl;
        cout << "Rooms: " << Rooms << endl;
        cout << "Area: " << Area << endl;
    }
};

class House : public Building //������House���̳�Building
{
private:
    unsigned Bedrooms, Washrooms;
public:
    House(unsigned floors, unsigned rooms, double area,
          unsigned bedrooms, unsigned washrooms):
        Building(floors, rooms, area),
        Bedrooms(bedrooms), Washrooms(washrooms){}
    void DisplayHouse() //��Ӧ���������
    {
        DisplayBuilding();
        cout << "Bedrooms: " << Bedrooms << endl;
        cout << "Washrooms: " << Washrooms << endl;
    }
};

class Office : public Building //������Office���̳�Building
{
private:
    unsigned Extinguishers, Telephones;
public:
    Office(unsigned floors, unsigned rooms, double area,
          unsigned extinguishers, unsigned telephones):
        Building(floors, rooms, area),
        Extinguishers(extinguishers), Telephones(telephones){}
    void DisplayOffice() //��Ӧ���������
    {
        DisplayBuilding();
        cout << "Extinguishers: " << Extinguishers << endl;
        cout << "Telephones: " << Telephones << endl;
    }
};

int main() //������
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
