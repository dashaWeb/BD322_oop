#include <iostream>
#include <set>

#include <algorithm>

using namespace std;

//template<typename ConType, typename TE>
//void print(const ConType& con, const string& prompt = "")
//{
//	cout << prompt << "\n\t";
//	ostream_iterator<TE> outIt(cout, "\t");
//	copy(con.begin(), con.end(), outIt);
//	cout << endl;
//}

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
	multiset<int> ml{ 10,5,21,45,10,7,10,8,10 };
	//multiset<int,greater<int>> ml{ 10,5,21,45,10,7,10,8,10 };
	//print<multiset<int>,int>(ml, "Print Multiset");
	print(ml, "Print Multiset");

	for (auto i = ml.begin(); i != ml.end(); i++)
	{
		cout << *i << "\t";
	}cout << endl;

	for (auto i = ml.rbegin(); i != ml.rend(); i++)
	{
		cout << *i << "\t";
	}cout << endl;

	int key = 10;
	auto it = ml.find(key);
	cout << distance(ml.begin(), it) << endl;
	ml.erase(it);
	print(ml, "Print Multiset");
	ml.insert(13);
	print(ml, "Print Multiset");
	it = ml.lower_bound(key); // >= key
	cout << "Lower bound :: " << *it << "\t ind :: " << distance(ml.begin(), it) << endl;
	it = ml.upper_bound(key); // > key
	cout << "Upper bound :: " << *it << "\t ind :: " << distance(ml.begin(), it) << endl;


	set<int> st(ml.begin(), ml.end());
	print(st, "Print Set :: ");
	set<int> st2{ 10,15,3,47,5,21,3,555,222,666,333 };
	print(st2, "Print Set :: ");

	cout << "\n\n----------- Union ------------\n";
	ostream_iterator<int> alIt(cout, "\t");
	set_union(begin(st), end(st), begin(st2), end(st2), alIt);

	cout << "\n\n----------- Intersection ------------\n";
	set_intersection(begin(st), end(st), begin(st2), end(st2), alIt);
	cout << "\n\n----------- Difference (st - st2) ------------\n";
	set_difference(begin(st), end(st), begin(st2), end(st2), alIt);
	cout << "\n\n----------- Difference (st2 - st) ------------\n";
	set_difference(begin(st2), end(st2), begin(st), end(st),  alIt);
	cout << endl;
}
