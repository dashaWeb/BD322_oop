#include <iostream>
#include <forward_list>
#include <list>
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
int main()
{
	forward_list<int> flist{ 10,2,5,8,7,4,69,5,4,1 };
	print(flist, "\nPrint Forward List");

	flist.push_front(22);
	print(flist, "\nPrint Forward List push_front");
	int index = 2;
	auto it = flist.begin();
	advance(it, index);
	cout << "Value offset :: " << *it << endl;
	flist.insert_after(it, 333);
	print(flist, "\nPrint Forward List insert_after");

	int value = 4;
	it = find(flist.begin(), flist.end(), value);
	while(it != flist.end())
	{
		cout << value << " was found \n";
		auto tmpIt = it;
		++tmpIt;
		if (tmpIt != flist.end()) {
			flist.erase_after(it);
		}
		else {
			cout << "Erase after " << value << " is impossible {last element}" << endl;
			break;
		}
		advance(it, 1);
		it = find(it, flist.end(), value);

	}
	print(flist, "\nPrint Forward List erase_after");

	flist.sort();
	print(flist, "\nPrint Forward List sorted");
	flist.sort(greater<int>());
	print(flist, "\nPrint Forward List sorted");
	flist.remove(value);
	print(flist, "\nPrint Forward List remove");

	int bound = 10;
	flist.remove_if([bound](const auto a) {return a < bound and a > 5; });
	print(flist, "\nPrint Forward List remove_if");


	system("cls");

	list<string> li{ "c++","c#","Python","java" };
	print(li, "\nPrint List ");
	li.push_back("assempler");
	li.push_front("js");
	print(li, "\nPrint List adding");
	char letter = 'c';
	li.remove_if([letter](const auto el) {return el.find(letter) != string::npos /*-1*/; });
	print(li, "\nPrint List remove_if");

	li.sort(greater<string>());
	print(li, "\nPrint List remove_if");
}
