#include "Point.h"

Point Point::operator+(const Point& other) const
{
	Point res;
	res.x = this->x + other.x;
	res.y = this->y + other.y;
	return res;
}

Point Point::operator-(const Point& other) const
{
	Point res;
	res.x = this->x - other.x;
	res.y = this->y - other.y;
	return res;
}

void Point::operator+=(const int& value)
{
	this->x += value;
	this->y += value;
}

bool Point::operator==(const Point& other) const
{
	return this->x == other.x and this->y == other.y;
}

bool Point::operator!=(const Point& other) const
{
	return !(*this == other); // ����������� �������� �������� ����� == , � ���������� ���������
}

Point& Point::operator++()
{
	++x;
	++y;
	return *this;
}

Point Point::operator++(int)
{
	Point tmp(*this); // copy ctor, ����� ���� ������ ���� , �������� � tmp
	/*++x; // ������� ���� ��'���� this
	++y;*/
	++*this; // ��� ����� ���, ��������� �������� ����� ++ ����������
	return tmp; // ��������� ������ ������ ��'����
}

string Point::getPoint() const
{
	return "(" + to_string(this->x) + "," + to_string(this->y) + ")";
}
