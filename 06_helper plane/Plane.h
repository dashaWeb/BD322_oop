#pragma once
#include <iostream>
using std::cout;
using std::string;

//Створити клас Airplane(літак).За допомогою перевантаження операторів реалізувати :
//■ Перевірку на рівність типів літаків(операція « == »);
//■ Збільшення і зменшення пасажирів в салоні літака
//(операції «++» і «––» в префіксній формі);
//■ Порівняння двох літаків за максимально можливою
//кількістю пасажирів на борту(операція « > »).
enum Type
{
	TYPE_1, TYPE_2, TYPE_3
};
class Plane
{
public:
	Plane(const string name, const size_t& seeds, const size_t& max_seeds = 40, Type type = Type::TYPE_1) :name{ name }, seeds{ seeds }, max_seeds{ max_seeds }, type{type}
	{}
	bool operator ==(const Plane& other) const;
	bool operator !=(const Plane& other) const;
	bool operator >(const Plane& other) const;
	Plane& operator++();
	Plane& operator--();
	void print() const;
private:
	Type type;
	size_t seeds;
	size_t max_seeds;
	string name;
};

