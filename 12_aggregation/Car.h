#pragma once
#include <iostream>
#include "Engine.h"
using namespace std;
class Car
{
public:
	Car() = default;
	Car(string brand, size_t max_speed, Engine engine)
		:brand{ brand }, engine{ engine }, max_speed{max_speed}
	{

	}
	Car(string brand, size_t max_speed, string model, size_t power, double volume)
		:brand{ brand }, engine(model, power, volume), max_speed{max_speed}
	{

	} void print() const
	{
		cout << "Car Brand :: " << brand << "\t max_speed :: " << max_speed << endl;
		cout << "\t Engine :: ";
		engine.print();
		cout << endl;
	}
private:
	string brand;
	Engine engine;
	size_t max_speed;
};

