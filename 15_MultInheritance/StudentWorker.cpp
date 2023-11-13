#include "StudentWorker.h"

StudentWorker::StudentWorker(const string& name, const string& position, const string& specialization)
	:Person(name),
	Student("++++", specialization), Employee("----", position)
{
	cout << "\t\t----- Ctor Student_Employee " << Student::name << " - " << Employee::name << endl;
}

StudentWorker::StudentWorker(const Student& student, const Employee& employee)
	:Person(employee),
	Student(student), Employee(employee)
{
}

StudentWorker::~StudentWorker()
{
	cout << "Dtor Student_Employee :: " << Student::name << " - " << Employee::name << endl;
}

void StudentWorker::print() const
{
	/*Student::print();
	Employee::print();*/
	cout << "Name           :: " << name << endl;
	cout << "Position       :: " << position << endl;
	cout << "Sprcialization :: " << specialization << endl;
}
