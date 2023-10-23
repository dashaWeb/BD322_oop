#include <iostream>
#include "String.h"
using namespace std;


int main()
{
    String line_1("Lorem ipsum");
    cout << "Line 1 :: " << line_1.getLine() << endl;

    String line_2 = line_1;
    String line_3;
    cout << "Line 2 :: " << line_2.getLine() << endl;

    line_2.setLine("Hello World");
    cout << "Set new value line_2" << endl;
    cout << "Line 1 :: " << line_1.getLine() << endl;
    cout << "Line 2 :: " << line_2.getLine() << endl;

    line_3 = line_1;
    cout << "\n Copy line_1" << endl;
    cout << "Line 1 :: " << line_1.getLine() << endl;
    cout << "Line 3 :: " << line_3.getLine() << endl;
    line_3.setLine("Yellow");
    cout << "Set new value line_3" << endl;
    cout << "Line 1 :: " << line_1.getLine() << endl;
    cout << "Line 3 :: " << line_3.getLine() << endl;
}
