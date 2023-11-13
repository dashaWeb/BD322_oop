#pragma once
#include <iostream>
#include "Person.h"
using namespace std;
class Student
	:virtual public Person
{
public:
	Student(const string& name, const string& specialization);
	~Student();
	void print() const;
protected:
	//string name;
	string specialization;
};

