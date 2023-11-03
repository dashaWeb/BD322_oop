#include <iostream>
#include "Point.h"
using namespace std;
int main()
{
   
	Point A(5, 5);
	Point B(4, 10);
	Point C = A + B;
	Point D = A - B;
	Point E = A;
	cout << "A" << A.getPoint() << " + B" << B.getPoint() << " = " << "C" << C.getPoint() << endl;
	cout << "A" << A.getPoint() << " - B" << B.getPoint() << " = " << "C" << D.getPoint() << endl;
	cout << boolalpha << " == " << (A == E) << endl;
	cout << boolalpha << " != " << (A != E) << endl;
	cout << "A :: " << A.getPoint() << endl;;
	cout << "++a :: " << (++A).getPoint() << endl;
	cout << "a++ :: " << (A++).getPoint() << endl;
	cout << "A :: " << A.getPoint() << endl;;
	A += 10;
	cout << "A :: " << A.getPoint() << endl;;

	/*int a = 5;
	a += 10;*/
	//cout << "Point A ::" << A << endl;
}
