#include <iostream>
#include "Fraction.h"
using namespace std;
int main()
{
    Fraction one(20, 45);
    Fraction two(3, 7);
    Fraction res = one + two;
    cout << one << " + " << two << " = " << res << endl;
    res = one % 2;
    cout << res.getFraction() << endl;

}
