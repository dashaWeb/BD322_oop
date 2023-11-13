#include "Employee.h"

void Employee::print() const
{
	cout << "Name employee     :: " << this->name << endl;
	cout << "Position employee :: " << this->position << endl;
}

Employee::~Employee()
{
	cout << "Dtor Employee :: " << this->name << endl;
}
