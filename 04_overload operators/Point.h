#pragma once
#include <iostream>
#include <string>
using namespace std;
class Point
{
public:
	Point() = default;
	Point(const int& x, const int& y)
		:x{ x }, y{y}
	{

	}
	Point(const int& x):Point(x,0)
	{}
	// +,-,*,/,%
	Point operator +(const Point& other) const; // a + b this(left); other(right)
	Point operator -(const Point& other) const; // a + b this(left); other(right)
	void operator +=(const int& value);
	// ==, !=, >=, <=, >, <
	bool operator ==(const Point& other) const;
	bool operator !=(const Point& other) const;
	// ++ unary
	Point& operator++(); // this - вже прийшов , префіксна форма;
	Point operator++(int); // this - вже прийшов , постфіксна форма має приймати фіктивний параметр;
	string getPoint() const;
private:
	int x, y;
};

