#pragma once
#include "Wolf.h"
class Dog :public Wolf
{
public:
	Dog() = default;
	Dog(const string& name,const size_t& age, const size_t& weight )
		:Wolf(name,age,weight)
	{

	}
	void print() const override
	{
		cout << "\t----------Dog---------" << endl;
		Animal::print();
		cout << "Weight :: " << weight << endl;
	}
};

