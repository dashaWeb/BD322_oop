#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

template <typename ContType>
void print(const ContType& cont, const string& prompt = "")
{
	cout << prompt << endl;
	cout << "\t";
	for (const auto& el : cont)
	{
		cout << el << "\t";
	}cout << endl;
}

bool div_3(int number)
{
	return number % 3 == 0;
}

int numb(int number)
{
	return number + 2;
}
int main()
{
	const size_t SIZE = 5;
	array<int, SIZE> arr{ 10,33,4,-5,7 };
	//print(arr, "Print container array");
	cout << "Print container array {index} :: \n\t";
	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	cout << "Print container array {iterator} :: \n\t";
	for (array<int, SIZE>::iterator it = arr.begin(); it != arr.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;

	cout << "Print container array {reverse_iterator} :: \n\t";
	for (array<int, SIZE>::reverse_iterator it = arr.rbegin(); it != arr.rend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;

	cout << "Test exception method at() :: \n\t";
	try
	{
		arr.at(5) = 100;
	}
	catch (const std::exception& ex)
	{
		cout << "Bad index :: " << ex.what() << endl;
	}

	array<int, SIZE>::iterator it = min_element(arr.begin(), arr.end());
	cout << "Min in array :: " << *it << endl;
	*it *= -1;
	it = min_element(arr.begin(), arr.end());
	cout << "Min in array after(*-1) :: " << *it << endl;
	it = max_element(arr.begin(), arr.end());
	cout << "Max in array :: " << *it << endl;

	vector<int> v(arr.rbegin(), arr.rend());
	print(v, "Print vector");
	v.push_back(333);
	print(v, "Print vector {push_back(333)}");
	v.insert(v.begin() + v.size() / 2, 777);
	print(v, "Print vector {insert(777)}");
	/*v.pop_back();
	print(v, "Print vector {pop_back()}");
	v.erase(v.begin() + v.size() / 2);
	print(v, "Print vector {erase()}");*/



	deque<int> d(v.begin(), v.begin() + v.size() / 2);
	print(d, "Print deque ( copy 1-st hala of vector ) ");
	deque<int> dd(v.begin() + v.size() / 2, v.end());
	print(dd, "Print deque ( copy 2-nd hala of vector ) ");
	cout << "deque size :: " << d.size() << endl;
	d.resize(v.size() - 1);
	cout << "deque resize:: " << d.size() << endl;
	copy(v.rbegin(), v.rend() - v.size() / 2, d.begin());
	print(d, "Print deque ( deque copy ) ");
	d.push_back(777);
	d.push_front(777);
	print(d, "Print deque (  ) ");


	auto dit = find(d.begin(), d.end(), 777);
	while (dit != d.end())
	{
		cout << " Find element value :: " << *dit << "\t index :: " << dit - d.begin() << endl;
		dit = find(dit + 1, d.end(), 777);
	}

	cout << "Count of value :: " << count(d.begin(), d.end(), 777) << endl;
	auto itt = find_if(d.begin(), d.end(), div_3);
	while (itt != d.end())
	{
		cout << "Value :: " << *itt << "\t Poisition :: " << itt - d.begin() << endl;
		itt = find_if(itt + 1, d.end(), div_3);
	}
	print(d, "Print deque ( before ) ");
	transform(d.begin(), d.end(), d.begin(), numb);
	print(d, "Print deque ( after  ) ");

	sort(d.begin(), d.end());
	print(d, "Print deque ( sort ABC  ) ");
	sort(d.rbegin(), d.rend());
	print(d, "Print deque ( sort DEST  ) ");
	/*int test = 22;
	auto func = [&](int a, int b, int c)->double {
		double sum = (double)a + b + c + test;
		return sum;
	};

	cout << func(1, 2, 3) << endl;*/
	transform(d.begin(), d.end(), d.begin(), [](int a) {return a += 10; });
	print(d, "Print deque ( after  ) ");
	cout << "Count of value :: " << count_if(d.begin(), d.end(), [](int a) {return a > 100; }) << endl;
	itt = find_if(d.begin(), d.end(), [](int a) {return a == 789; });
	while (itt != d.end())
	{
		cout << "Value :: " << *itt << "\t Poisition :: " << itt - d.begin() << endl;
		itt = find_if(itt + 1, d.end(), [](int a) {return a == 789; });
	}
	
}
