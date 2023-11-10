#include <iostream>
#include "Car.h"
using namespace std;
int main()
{
    Engine eng("AB", 200, 2.1);
    eng.print();
    cout << endl;

    Car audi("Audi", 300, eng);
    audi.print();

    Car ford("Ford", 270, { "BB",300,2.5 });
    ford.print();

    Car bmw("Bmw", 350, "AA", 210, 2.7);
    bmw.print();
}
