#include <iostream>
#include "names.h"

using namespace Shape;
using Shape::Rectanle::width;
//using namespace StudentST;
//using namespace StudentMK;
int main()
{
    std::cout << "Area Square :: " << areaSquare(width) << std::endl;

    StudentST::Student stud("Oleg", 22);
    StudentMK::Student studM("Masha", 12);
    stud.print();
    studM.print();

}
