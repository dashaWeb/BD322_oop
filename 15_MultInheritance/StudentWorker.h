#pragma once
#include "Employee.h"
#include "Student.h"
class StudentWorker
	: protected Student, protected Employee
{
public:
	StudentWorker(const string& name, const string& position, const string& specialization);
	StudentWorker(const Student& student, const Employee& employee);
	~StudentWorker();
	void print() const;
};

