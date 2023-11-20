#include <iostream>
#include "MyException.h"
using namespace std;
double div(double a, double b)
{
	const double LIMIT = 1'000'000;
	if (b == 0) {
		throw DivByZeroException();
	}
	if (b > LIMIT)
	{
		throw TooBigDivisionException("Too big number", b);
	}
	if (b < -LIMIT)
	{
		throw TooSmallDivisionException("Too small number", b);
	}
	return a / b;
}
int main()
{
	double a, b, result;
	cout << "Enter Two number :: ";
	while (cin >> a >> b)
	{
		try
		{
			result = div(a, b);
			cout << a << " / " << b << " = " << result << endl;
		}
		/*catch (const DivByZeroException& ex)
		{
			cout << "Exception :: " << typeid(ex).name() << "\t Text :: " << ex.what() << endl;
		}*/
		/*catch (const TooBigDivisionException& ex)
		{
			cout << "Exception :: " << typeid(ex).name() << "\t Text :: " << ex.what() << endl;
			cout << "Bad value :: " << ex.getValue() << endl;
		}
		catch (const TooSmallDivisionException& ex)
		{
			cout << "Exception :: " << typeid(ex).name() << "\t Text :: " << ex.what() << endl;
			cout << "Bad value :: " << ex.getValue() << endl;
		}*/
		catch (const exception& ex)
		{
			cout << "My Exception :: " << typeid(ex).name() << "\t Text :: " << ex.what() << endl;
			//cout << "Bad value :: " << ex.getValue() << endl;
		}
		catch (...)
		{
			cout << "End catch" << endl;
		}
	}
}
