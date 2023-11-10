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
	void print() 
	{
		Animal::print();
		cout << "Weight :: " << weight << endl;
		this->setAge(45);
		
	}
private:
	size_t weight;
};

