#include <iostream>
//#include "Employee.h"
//#include "Student.h"
#include "StudentWorker.h"
using namespace std;
int main()
{

    Student stud("Denis", "CS");
    stud.print();

    Employee emp("DENIS", "Manager");
    emp.print();

    

    cout << endl << endl;
    //StudentWorker stw("Ivan", "Manager", "CS");
    StudentWorker stw(stud,emp);
    stw.print();

}

