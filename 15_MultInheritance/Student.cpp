#include "Student.h"

Student::Student(const string& name, const string& specialization)
	:Person(name)/*name{name}*/, specialization{specialization}
{
	cout << "Ctor Student :: " << this->name << endl;
}

Student::~Student()
{
	cout << "Dtor Student :: " << this->name << endl;
}

void Student::print() const
{
	cout << "Name student           :: " << this->name << endl;
	cout << "Specialization student :: " << this->specialization << endl;
}
