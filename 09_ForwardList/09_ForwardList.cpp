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
    FList<int> clone = list.clone();


    cout << "List_ 1 :: ";
    list.print();

    cout << "Clone   :: ";
    clone.print();


    list.removeHead();
    cout << endl;
    cout << "List_ 1 :: ";
    list.print();

    cout << "Clone   :: ";
    clone.print();

    clone.removeHead();
    clone.removeHead();
    cout << endl;
    cout << "List_ 1 :: ";
    list.print();

    cout << "Clone   :: ";
    clone.print();

    /*cout << "List size :: " << list.getSize() << endl;
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
    cout << "List size :: " << list.getSize() << endl;*/
}
