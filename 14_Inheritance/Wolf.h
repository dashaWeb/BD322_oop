#pragma once
#include "Animal.h"
class Wolf :protected Animal // private, protected
{
public:
	Wolf(string name, const size_t& age, size_t weight) 
		:Animal(name,age), weight{weight}
	{
		cout << "Wolf ctor (" << this->id << ". " << this->name << ")" << endl;
	}
	Wolf() = default;
	~Wolf()
	{
		cout << "Wolf dtor (" << this->id << ". " << this->name << ")" << endl;
	}
	virtual void print() const override
	{
		cout << "\t----------Wolf---------" << endl;
		Animal::print();
		cout << "Weight :: " << weight << endl;
	}
	void eat() const override;
	void move() const override;
protected:
	size_t weight;
};

