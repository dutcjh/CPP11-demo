#ifndef __SALES_ITEM_H__
#define __SALES_ITEM_H__
#include <iostream>
#include <string>

using namespace std;

class Sales_data
{
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double avg_price() const
	{
		return units_sold ? revenue / units_sold : 0;
	}
public:
	Sales_data() = default;
	Sales_data(const std::string &s, unsigned n, double p):
		bookNo(s), units_sold(n), revenue(p*n){ }
	Sales_data(const std::string &s): bookNo(s){ }
	Sales_data(std::istream& is) { is >> *this; }
	std::string isbn() const { return bookNo; }
	friend istream &operator >> (istream &is, Sales_data &item);
	friend ostream &operator << (ostream &os, const Sales_data &item);
	friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
	Sales_data& operator+=(const Sales_data &rhs);
};

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn() &&
		lhs.units_sold == rhs.units_sold &&
		lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);
}

istream &operator>>(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = price * item.units_sold;
	else
		item = Sales_data();
	return is;
}

ostream &operator<<(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
#endif  // __SALES_ITEM_H__
