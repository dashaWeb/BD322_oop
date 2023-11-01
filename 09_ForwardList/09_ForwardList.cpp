#include <iostream>
#include "FList.h"
using namespace std;
int main()
{
    FList<int> list;

    list.addHead(25);
    list.print();
    list.addHead(33);
    list.addHead(15);
    list.addHead(12);
    list.print();
    cout << "List size :: " << list.getSize() << endl;
    list.removeHead();
    list.print();
    cout << "List size :: " << list.getSize() << endl;
    list.removeHead();
    list.print();
    cout << "List size :: " << list.getSize() << endl;
    list.removeHead();
    list.print();
    cout << "List size :: " << list.getSize() << endl;
    list.removeHead();
    list.print();
    cout << "List size :: " << list.getSize() << endl;
    list.removeHead();
    list.print();
    cout << "List size :: " << list.getSize() << endl;
}
