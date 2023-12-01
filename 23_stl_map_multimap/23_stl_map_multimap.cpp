#include <iostream>
#include <map>

#include <algorithm>

using namespace std;

typedef int* ptrInt; // c - style
using id = int;
using name = string;
using author = string;
using title = string;

template <typename T>
void print(const T& map, const string& prompt)
{
	cout << prompt << "\n";
	for (auto& p : map)
	{
		cout << "\t Id :: " << p.first << "\t Name :: " << p.second << endl;
	}
}


int main()
{
	map<id, name> people
	{
		pair<id,name>{444,"Anna"},
		make_pair(333,"Ivan"),
		{777,"Olena"},

	};
	/*pair<id, name> test{ 1,"Oleg" };
	test.second, test.first;*/
	print(people, "Print map :: ");
	people[777] = "Taras";
	people[222] = "Diana";
	print(people, "Print map :: ");
	people.insert({ 111,"Denis" });
	people.insert({ 111,"Pasha" });

	print(people, "Print map :: ");

	id key = 1000;
	//cout << "Test by get key :: " << people[key] << endl;
	try
	{
		cout << "Test by get key :: " << people.at(key) << endl;

	}
	catch (const std::exception& ex)
	{
		cout << "\t\t Not find key " << key << endl;
		cout << "\t\t Error message " << ex.what() << endl;
	}

	print(people, "Print map :: ");
	cout << "\n\nPrint test iterator :: \n\n";
	for (auto i = people.begin(); i != people.end(); i++)
	{
		cout << i->first << ". " << i->second << endl;
	}
	cout << "\n\nPrint test reverse iterator :: \n\n";
	for (auto i = people.rbegin(); i != people.rend(); i++)
	{
		cout << i->first << ". " << i->second << endl;
	}

	auto it = people.begin();
	advance(it, 2);
	key = 222;
	//it = people.find(key);
	it = find_if(people.begin(), people.end(), [](auto el) {return el.second == "Anna"; });
	if (it != people.end())
	{
		people.erase(it);

	}
	else {
		cout << "Key not found " << endl;
	}
	print(people, "Print map {erase} :: ");


	it = people.lower_bound(key);
	if (it != people.end())
	{
		cout << it->first << ". " << it->second << endl;

	}
	else {
		cout << "Key not found " << endl;
	}
	it = people.upper_bound(key);
	if (it != people.end())
	{
		cout << it->first << ". " << it->second << endl;

	}
	else {
		cout << "Key not found " << endl;
	}
	cout << "Min key :: " << people.begin()->first << endl;
	cout << "Max key :: " << people.rbegin()->first << endl;

	system("cls");

	multimap<author, title> library
	{
		{"Tony Gaddis","C++ for beginners"},
		{"Tony Gaddis","Python for beginnes"},
		{"Stiven Prata","Modern C++"},
		{"Tony Gaddis","Java for beginnes"},
		{"Stiven Prata","Modern C"},
	};
	print(library, "Print multimap :: ");
	library.insert({ "G. Shildt","Base of C#" });
	print(library, "Print multimap :: ");
	//library.erase("Tony Gaddis");
	auto itt = library.find("Tony Gaddis");
	cout << itt->first << " :: " << itt->second << endl;
	itt = find_if(library.begin(), library.end(), [](auto book) {return book.first == "Stiven Prata" and book.second == "Modern C++"; });
	cout << itt->first << " :: " << itt->second << endl;
	library.erase(itt);
	print(library, "Print multimap :: ");
	cout << endl;

	auto range = library.equal_range("Tony Gaddis");
	for (auto i = range.first; i != range.second; i++)
	{
		cout << i->first << " :: " << i->second << endl;
	}


}

