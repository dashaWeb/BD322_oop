#pragma once
#include <iostream>
using namespace std;
class Animal abstract
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
	virtual void print() const
	{
		cout << "\t\t Animal " << endl;
		cout << this->id <<  ". Name :: " << this->name << "\t Age :: " << this->age << endl;
	}
	virtual void eat() const = 0;
	virtual void move() const = 0;

private:
	size_t age;
	static size_t last_id;
protected:
	size_t id;
	string name;
};


