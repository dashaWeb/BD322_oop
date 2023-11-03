#include <iostream>
using namespace std;


class City {
public:
	void print() const 
	{
		cout << "\t City       :: " << getCity() << endl;
		cout << "\t Country    :: " << getCountry() << endl;
		cout << "\t Population :: " << getPopulation() << endl << endl;
	}
	const char* getCity() const // good style
	{
		return this->city;
	}
	const char* getCountry() const // good style
	{
		return this->country;
	}
	inline const size_t& getPopulation() const;
	void setCity(const char* city) 
	{
		strCopy(this->city, city);
	}
	void setCountry(const char* country) {
		strCopy(this->country, country);
	}
	void setPopulation(const size_t& population) {
		this->population = population;
	}
	inline bool isValidName(const char* name) const;
	City() // default ctor
	{
		cout << "Default ctor" << endl;
		strCopy(this->city, "NoCity");
		strCopy(this->country, "NoCountry");
	}
	City(const char* city):City(city, "NoCountry")
	{
		cout << "Parametrs 1 ctor" << endl;
	}
	City(const char* city, const char* country) :City(city, country, 0)
	{
		cout << "Parametrs 2 ctor" << endl;
	}
	City(const char* city, const char* country, int population) {
		cout << "Parametrs 3 ctor" << endl;
		strCopy(this->city, city);
		strCopy(this->country, country);
		this->population = population;
	}
	~City()
	{
		cout << "Dtor :: " << this->city << endl;
		if (this->city != nullptr) {
			delete this->city;
		}
		if (this->country != nullptr) {
			delete this->country;
		}
	}

private:
	char* country = nullptr;
	char* city = nullptr;
	size_t population;
	void strCopy(char*& dest, const char* other) {
		if (!isValidName(other)) return;
		if (dest != nullptr) {
			delete[] dest;
		}
		dest = new char[strlen(other) + 1];
		strcpy_s(dest, strlen(other) + 1, other);
	}
};

int main()
{
	City rivne("Rivne","Ukraine", 243934);
	cout << endl;
	City lviv("Lviv", "Ukraine");
	cout << endl;
	City* kyiv = new City("Kyiv");
	kyiv->print();
	rivne.print();

	kyiv->setCity(nullptr);
	kyiv->print();

	system("pause");
	delete kyiv;
	cout << endl;
	system("pause");
}

inline const size_t& City::getPopulation() const
{
	return this->population;
}

inline bool City::isValidName(const char* name) const
{
	return name != nullptr && name[0] != '\0' && name[0] != ' ';
}
