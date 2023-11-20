#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
    //string str = "1234567";
    /*string str = "d1a2d3f45";

	try
	{
		int value = stoi(str);
		cout << "Value :: " << value << "\t +1 :: " << value+1 << endl;
	}
	catch (const std::exception& ex)
	{
		cout << "Type Exeption :: " << typeid(ex).name() << endl;
		cout << "Value exception :: " << ex.what() << endl;
	}*/

	//string str = "ABCD";
	vector<int> numbers{ 1,2,3,4,5 };
	try
	{
		cout << "number[6] :: " << numbers.at(6) << endl;
	}
	catch (const std::exception& ex)
	{
		cout << "Type Exeption :: " << typeid(ex).name() << endl;
		cout << "Value exception :: " << ex.what() << endl;
	}


	cout << "Finally" << endl;
	

}
