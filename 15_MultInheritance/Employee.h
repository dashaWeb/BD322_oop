#pragma once
#include <iostream>
#include "Person.h"
using namespace std;
class Employee
	:virtual public Person
{
public:
	Employee(const string& name, const string& position):
		Person(name)/*name{name}*/, position{position}{
		cout << "Ctor Employee :: " << this->name << endl;
	}
	void print() const;
	~Employee();
protected:
	//string name; 
	string position;
};

