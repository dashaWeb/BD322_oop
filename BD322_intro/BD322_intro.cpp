#include <iostream>
#include <string>
using namespace std;


const size_t MIN_POWER = 50;
const size_t MAX_POWER = 1000;

const double MIN_VOLUME = 0.7;
const double MAX_VOLUME = 6;

const size_t MAX_SPEED_LOW = 100;
const size_t MAX_SPEED_UP = 350;


struct Date
{
	int day, month, year;
	string getDate()
	{
		string date = "";
		// 02.03.2012
		date += (day < 10 ? "0" + to_string(day) : to_string(day));
		date += ".";
		date += (month < 10 ? "0" + to_string(month) : to_string(month));
		date += ".";
		date += to_string(year);
		return date;
	}
	void input() {
		cout << "\t Enter Date      :: ";
		cin >> day >> month >> year;
	}
};

class Car {
private:
	string color = "None";
	string brand = "NoBrand";
	size_t power = MIN_POWER;
	double volume = MIN_VOLUME;
	size_t max_speed = MAX_SPEED_LOW;
	Date date{};
public:
	//Car() // default ctor
	//{
	//    color = "None";
	//    brand = "non Brand";
	//    power = MIN_POWER;
	//    volume = MIN_VOLUME;
	//    max_speed = MAX_SPEED_LOW;
	//}
	Car(const string& brand, const string& color, const Date date)
	{
		//_color = color;
		this->color = color;
		setBrand(brand); // краще, в методі є перевірка
		this->date = date;
	}
	string getBrand() { // задача гетера - повертати значення поля
		return this->brand;
	}
	string getColor() { // задача гетера - повертати значення поля
		return this->color;
	}
	size_t getPower()
	{
		return this->power;
	}
	size_t getSpeed()
	{
		return this->max_speed;
	}
	double getVolume()
	{
		return this->volume;
	}
	Date getDate() {
		return this->date;
	}
	void setBrand(const string& brand) { // задача сетера - присвоїти значення поля
		// way 1
		/*if (brand.empty() || brand == " ") {
			cout << "Error brand" << endl;
			this->brand = "NoBrand";
		}
		else
		{
			this->brand = brand;
		}*/
		//way 2
		/*if (brand.empty() || brand == " ") {
			cout << "Error brand" << endl;
			this->brand = "NoBrand";
			return;
		}
		this->brand = brand;*/
		// way 3
		if (!brand.empty() && brand != " ") {
			this->brand = brand;
		}
	}
	void setColor(const string& color) {
		if (!color.empty() && color != " ") {
			this->color = color;
		}
	}
	void setPower(const size_t& power) {
		if (power >= MIN_POWER && power <= MAX_POWER) {
			this->power = power;
		}
	}
	void setVolume(const double& volume) {
		if (volume >= MIN_VOLUME && volume <= MAX_VOLUME) {
			this->volume = volume;
		}
	}
	void setSpeed(const size_t& speed) {
		if (speed >= MAX_SPEED_LOW && speed <= MAX_SPEED_UP) {
			this->max_speed = speed;
		}
	}
	void print() {
		cout << "\n\n==========================================\n\n";
		cout << "\t Brand     :: " << getBrand() << endl;
		cout << "\t Color     :: " << getColor() << endl;
		cout << "\t Power     :: " << getPower() << endl;
		cout << "\t Volume    :: " << getVolume() << endl;
		cout << "\t Max speed :: " << getSpeed() << endl;
		cout << "\t Date      :: " << getDate().getDate() << endl;
	}
	void input() {
		string text;
		size_t value;
		double volume;
		cout << "\n\n==========================================\n\n";
		cout << "\t Enter Brand     :: "; getline(cin, text); setBrand(text);
		cout << "\t Enter Color     :: "; getline(cin, text); setColor(text);
		cout << "\t Enter Power     :: "; cin >> value; setPower(value);
		cout << "\t Enter Volume    :: "; cin >> volume; setVolume(volume);
		cout << "\t Enter Max speed :: "; cin >> value; setSpeed(value);
		this->date.input();
	}
	//private: // індикатор доступу закритий, тобто немає доступу до полів з основної програми лише в межах класу
	//public: // робить доступ до полів за межами класу через екземпляр класу(обєкта)
	//protected - захищений, приховувати поля від користувача, але надає доступ до класів наслідників
};



int main()
{
	Car ford("Ford", "Black", { 2,10,2019 });
	/*cout << "Brand :: " << ford.getBrand() << endl;
	ford.setBrand("Mazda");
	cout << "Brand :: " << ford.getBrand() << endl;*/
	ford.print();
	ford.input();
	ford.print();

}
