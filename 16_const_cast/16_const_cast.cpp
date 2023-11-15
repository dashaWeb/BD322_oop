#include <iostream>
using namespace std;



void fun(const int& value)
{
    //++value;
    cout << value << endl;
    ++const_cast<int&>(value);
    cout << value << endl;
    int& ref = const_cast<int&>(value);
    ref++;
    cout << value << endl;
}
void funString(const string& value)
{
    //++value;
    cout << value << endl;
    ++const_cast<string&>(value)[0];
    cout << value << endl;
    string& ref = const_cast<string&>(value);
    ref += "!!!!";
    cout << value << endl;
}
int main()
{
    fun(2);
    funString("Hello");
}

