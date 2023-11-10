#pragma once
#include <iostream>
using namespace std;
class Animal
{
public:
	Animal(string name, const size_t& age)
		:name{name}, age{age}{
		this->id = ++last_id;
		cout << "Animal ctor (" << this->id << ". " << this->name << ")" << endl;
	}
	Animal() = default;
	~Animal()
	{
		cout << "Animal dtor (" << this->id << ". " << this->name << ")" << endl;
	}
	void setName(string name) {
		if (name.size() == 0 || name[0] == ' ') {
			this->name = "None";
		}
		else {
			this->name = name;
		}
	}
	void setAge(const size_t& age) {
		this->age = age;
	}
	void print() const
	{
		cout << this->id <<  ". Name :: " << this->name << "\t Age :: " << this->age << endl;
	}
	string name;

private:
	size_t age;
	static size_t last_id;
protected:
	size_t id;
};

size_t Animal::last_id = 0;
