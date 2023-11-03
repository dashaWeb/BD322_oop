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
	return !(*this == other); // використали операцію написану раніше == , і заперечили результат
}

Point& Point::operator++()
{
	++x;
	++y;
	return *this;
}

Point Point::operator++(int)
{
	Point tmp(*this); // copy ctor, зняли копію самого себе , записали в tmp
	/*++x; // змінюємо поля об'єкта this
	++y;*/
	++*this; // або можна так, викликати написану раніше ++ префікстну
	return tmp; // повертаємо старий варіант об'єкта
}

string Point::getPoint() const
{
	return "(" + to_string(this->x) + "," + to_string(this->y) + ")";
}
