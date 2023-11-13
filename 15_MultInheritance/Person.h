#pragma once
#include <iostream>
using namespace std;
class Person
{
public:
	Person(const string& name) :
		name{ name } {
		cout << "Ctor Person :: " << this->name << endl;
	}
	~Person()
	{
		cout << "Dtor Person :: " << this->name << endl;
	}
	void print() const 
	{
		cout << "Person Name :: " << this->name << endl;
	}
protected:
	string name;
};

