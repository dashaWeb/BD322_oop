#include <iostream>
#include <string>
#include "Plane.h"
using namespace std;


int main()
{
	Plane one("Plane 1", 40,40);
	Plane two("Plane 2", 0, 20,Type::TYPE_2);

	one.print();
	two.print();

	cout << "Type :: " << boolalpha << (one == two) << endl;
	cout << "Max  :: " << boolalpha << (one > two) << endl;
	++one;
	--two;
	one.print();
	two.print();


}
