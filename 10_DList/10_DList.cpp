#include <iostream>
#include "DList.h"
using namespace std;
int main()
{
	DList<int> list;
	list.addHead(22);
	list.addHead(25);
	list.addHead(12);
	list.addHead(33);
	list.print();

	cout << "===============\n\n";

	list.addTail(111);
	list.addTail(13);
	list.addTail(55);
	cout << "Print         :: ";
	list.print();
	cout << "Print Reverse :: ";
	list.printR();
	list.removeHead();
	cout << "Print         :: ";
	list.print();


	list.removeData(13);
	cout << "Print         :: ";
	list.print();
	cout << "Print Reverse :: ";
	list.printR();

	DList<int> clone(list);
	cout << "Print         :: ";
	list.print();
	cout << "Print  Clone  :: ";
	clone.print();
	list.removeHead();
	cout << "Print         :: ";
	list.print();
	cout << "Print  Clone  :: ";
	clone.print();
	clone.removeHead();
	cout << "Print         :: ";
	list.print();
	cout << "Print  Clone  :: ";
	clone.print();

	DList<int> clone2;
	clone2 = clone;
	cout << "Print  Clone  :: ";
	clone.print();
	cout << "Print  Clone2 :: ";
	clone2.print();
	clone.removeHead();
	cout << "Print  Clone  :: ";
	clone.print();
	cout << "Print  Clone2 :: ";
	clone2.print();
}

