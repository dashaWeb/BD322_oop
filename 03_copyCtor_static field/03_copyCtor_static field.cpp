#include <iostream>
#include "Food.h"
using namespace std;


int main()
{
    Food milk("Milk", 100, 50);
    Food meat("Meat", 100, 50);
    Food bread("Bread", 100, 50);
    milk.print();
    meat.print();
    bread.print();

    cout << "\n\n===========================\n\n";
    cout << "Copy ctor :: " << endl;
    Food salad = meat;
    cout << "Clone :: " << endl;
    salad.print();
    salad.setName("Salad");
    cout << "Clone :: " << endl;
    salad.print();
    cout << "Origin :: " << endl;
    meat.print();
    Food apple;
    cout << "Operator = :: " << endl;
    milk = salad;
    milk.print();
    salad.print();
    salad.setName("Olivie");
    salad.setKkal(1000);
    milk.print();
    salad.print();
    cout << "Counter :: " << Food::getCounter() << endl;
}
