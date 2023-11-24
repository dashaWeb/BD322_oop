#pragma once
#include <iostream>
using std::cout;
using std::endl;
#include "IDevice.h"
class TV : public IDevice
{
	static const int MAX_VOLUME = 100;
	int max_channels;
	bool start = false;
	int volume = 0;
	int channel = 1;
public:
	TV(const int& max_channel = 10)
		:max_channels(max_channel){}
	void power();
	void plus();
	void minus();
	void next();
	void prev();
	void showInfo();
};

