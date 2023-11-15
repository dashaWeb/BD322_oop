#include <iostream>
#include <vector>
#include "Animal.h"
#include "Wolf.h"
#include "Lion.h"
#include "Dog.h"
using namespace std;
int main()
{

    //Animal an("Test", 4);
    Wolf wolf("Wolf", 2, 15);
    Lion lion("Lion", 2, 15);
    Dog dog("Dog", 2, 15);
    cout << "\n Test :: " << endl;
    wolf.print();
    lion.print();
    dog.print();
    cout << "\n\n";

    vector<Animal*> zoo = { &wolf,(Animal*)&lion, (Animal*)&dog };
    for (auto& item : zoo)
    {
        item->print();
        item->move();
        item->eat();
    }
    Animal** zoo = new Animal * [3] {new Wolf("Test", 4, 45), &wolf, &lion};
    for (size_t i = 0; i < 3; i++)
    {
        zoo[i]->print();
    }
}
