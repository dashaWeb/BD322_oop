#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	//Знайти  позиції всіх елементів v5, рівних заданому значенню(цикл з використанням ітератора).
	//Знайти кількість елементів, що співпадають  з  заданим значенням(count)

	vector<int> v{ 10,2,10,5,10,6,10 };
	int value = 10;
	auto it = find(v.begin(), v.end(), value);
	while (it != v.end())
	{
		cout << "value :: " << *it << "\t index :: " << it - v.begin() << endl;
		it = find(it+1, v.end(), value);
	}
	cout << "Count value {" << value << "} :: " << count(v.begin(), v.end(), value) << endl;

	vector<vector<int>>{
		{1, 2, 3},
		{}
	};

}
