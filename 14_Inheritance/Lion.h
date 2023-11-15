#pragma once
#include "Animal.h"
class Lion :public Animal // private, protected
{
public:
	Lion(string name, const size_t& age, size_t weight)
		:Animal(name, age), weight{ weight }
	{
		cout << "Wolf ctor (" << this->id << ". " << this->name << ")" << endl;
	}
	Lion() = default;
	~Lion()
	{
		cout << "Wolf dtor (" << this->id << ". " << this->name << ")" << endl;
	}
	void print() const
	{
		cout << "\t----------Lion---------" << endl;
		Animal::print();
		cout << "Weight :: " << weight << endl;
	}
	void eat() const override;
	void move() const override;
private:
	size_t weight;
};

