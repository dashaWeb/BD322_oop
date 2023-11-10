#pragma once
#include <iostream>
using namespace std;
class Engine
{
public:
	Engine(string model = "None Model", const size_t power = 250, const double& volume = 2.0)
		:model{ model }, power{ power }, volume{volume}
	{

	}
	Engine() = default;

	void print() const
	{
		cout << "Model :: " << model << "\t Power :: " << power << "\t Volume :: " << volume << "\t";
	}
private:
	string model;
	size_t power;
	double volume;
};

