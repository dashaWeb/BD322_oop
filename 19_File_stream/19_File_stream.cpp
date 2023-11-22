#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const size_t SIZE = 20;
class Train {
public:
	size_t number;
	char destination[SIZE];
	char from[SIZE];
	Train() = default;
	Train(const size_t& number, const char* dest, const char* from)
		:number(number)
	{
		strcpy_s(destination, dest);
		strcpy_s(this->from, from);
	}
	void print() const
	{
		cout << "\t Number of train :: " << number << endl;
		cout << "\t Place from      :: " << from << endl;
		cout << "\t Destination     :: " << destination << endl;
	}
};



int main()
{

	fstream file("train.dat", ios_base::out | ios_base::in | ios_base::binary);
	Train train(9, "Prague", "Lviv");
	file.write((char*)&train, sizeof(Train));

	Train arrTrain[2]{ {122,"Warsaw","Lviv"},{254,"Kyiv","Paris"} };
	file.write(reinterpret_cast<char*>(arrTrain), sizeof(arrTrain));


	vector<Train> trainVec{ {745,"Budapest","Kyiv"}, {214,"Rivne","Warsaw"} };
	file.write(reinterpret_cast<char*>(trainVec.data()), sizeof(Train) * trainVec.size());


	//read

	cout << "End bytes :: " << file.tellg() << endl;
	file.seekg(0);
	cout << "End bytes :: " << file.tellg() << endl;

	Train res;
	while (file.read(reinterpret_cast<char*>(&res), sizeof(Train)))
	{
		cout << "\n ----------------------- \n";
		res.print();
	}
	cout << "End bytes :: " << file.tellg() << endl;
	file.clear();
	file.seekg(0);
	cout << "End bytes :: " << file.tellg() << endl;

	vector<Train> results;
	while (file.read(reinterpret_cast<char*>(&res), sizeof(Train)))
	{
		results.push_back(res);
	}
	cout << "\n ----- Print vector ------ \n";
	for (auto& i : results)
	{
		cout << "\n ----------------------- \n";
		i.print();
	}

	cout << "Read file --> " << endl;
	cout << "End bytes :: " << file.tellg() << endl;
	file.clear();
	file.seekg(0, ios::end);
	cout << "End bytes :: " << file.tellg() << endl;

	results.clear();
	int count = file.tellg() / sizeof(Train);
	results.resize(count);
	cout << "Count trains :: " << count << endl;
	cout << "End bytes :: " << file.tellg() << endl;
	//file.clear();
	file.seekg(0);
	cout << "End bytes :: " << file.tellg() << endl;
	file.read(reinterpret_cast<char*>(results.data()), sizeof(Train) * count);
	for (auto& el : results)
	{
		cout << "\n ----------------------- \n";
		el.print();
	}

	int index = 2;
	cout << "End bytes :: " << file.tellg() << endl;
	//file.clear();
	file.seekg(sizeof(Train) * index);
	cout << "End bytes :: " << file.tellg() << endl;
	//file.read(reinterpret_cast<char*>(&res), sizeof(Train));

	Train ttr(999, "Rivne", "Poltava");
	file.write(reinterpret_cast<char*>( &ttr), sizeof(Train));
	cout << "Read train for index 2 :: " << endl;
	//res.print();

	// fstream --> Mode --> resd, write
	// ofstream --> write file
	// ifstream --> read write

	/*int number = 451244;
	ofstream file("number.txt");
	file << number;
	file.close();*/


	/*ifstream file("number.txt");
	int res;
	file >> res;
	file.close();
	cout << res << endl;*/


	/*string text = "Lorem ipsum";
	ofstream file("number.txt");
	file << text << endl;
	file.close();*/

	//ifstream file("text.txt");
	//string res;
	///*while (file >> res)
	//{
	//	cout << res << endl;
	//}*/
	///*char s[100];

	//while (file.getline(s,20))
	//{
	//	cout << s << endl;
	//}
	//file.close();*/
	//while (getline(file,res))
	//{
	//	cout << res << endl;
	//}


	/*int number = 451244;
	ofstream file("number.txt");
	file << number;
	file.close();*/

	//int number = 451244;
	//ofstream file("number.bin",ios_base::binary);
	//file.write((char*)&number, sizeof(int));
	//
	////file << number;
	//file.close();

}
