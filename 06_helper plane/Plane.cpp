#include "Plane.h"

bool Plane::operator==(const Plane& other) const
{
	return this->type == other.type;
}

bool Plane::operator!=(const Plane& other) const
{
	return !(this->type == other.type);
}

bool Plane::operator>(const Plane& other) const
{
	return this->max_seeds > other.max_seeds;
}

Plane& Plane::operator++()
{
	if (this->seeds < this->max_seeds) {
		this->seeds++;
	}
	return (*this);
}

Plane& Plane::operator--()
{
	if (this->seeds > 0) {
		this->seeds--;
	}
	return (*this);
}

void Plane::print() const
{
	cout << "\n";
	cout << "Name      :: " << name << "\n";
	cout << "Seeds     :: " << seeds << "\n";
	cout << "Max seeds :: " << max_seeds << "\n";
	cout << "Type      :: " << type << "\n";
}
