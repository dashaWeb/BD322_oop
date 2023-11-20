#include <iostream>
using namespace std;

// Exception - помилкова ситуація, потребує обробки
// try() catch

double div(double a, double b)
{
	const double LIMIT = 1'000'000;
	if (b == 0) {
		throw "Error:: division by zero";
	}
	if (b > LIMIT)
	{
		throw b;
	}
	if (b < -LIMIT)
	{
		throw (int)b;
	}
	return a / b;
}

void my_terminate() {
	cout << "my_terminate is working " << endl;
	exit(EXIT_FAILURE);
}
int main()
{
	set_terminate(my_terminate);
	double a, b;
	cout << "Enter two numbers :: ";
	while (cin >> a >> b)
	{
		try
		{
			cout << "Result :: " << div(a, b) << endl;
		}
		catch (const char* ex)
		{
			cout << ex << endl;
		}
		catch (double ex)
		{
			cout << "Double! Bad value >> " << ex << endl;
		}
		catch (...)
		{
			cout << "Something happened!!!" << endl;
		}
	}
}
