#include "area.h"

double Circle::CArea()
{
	return (3.14 * r * r);
}

double Circle::CLen()
{
	return (3.14 * 2 * r);
}

double Rectangle::RArea()
{
	return (a*b);
}

double Rectangle::RLen()
{
	return (2 * (a + b));
}
