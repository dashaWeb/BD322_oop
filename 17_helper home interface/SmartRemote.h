#pragma once
#include <conio.h>
#include "TV.h"

enum keys
{
	ENTER = 13, UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, ESC = 27
};
class SmartRemote
{
	IDevice* device;
public:
	SmartRemote(IDevice* device)
		:device(device)
	{}
	void setDevice(IDevice* device) {
		this->device = device;
	}
	void currentDevice() const
	{
		auto tv = dynamic_cast<TV*>(device);
		if (tv != nullptr) {
			cout << "TV" << endl;
		}
	}
	void testDevice()
	{
		while (true)
		{
			int s = _getch();
			if (s == keys::ESC) {
				break;
			}
			switch (s)
			{
			case ENTER:
				device->power(); break;
			case UP:
				device->next(); break;
			case DOWN:
				device->prev(); break;
			case LEFT:
				device->minus(); break;
			case RIGHT:
				device->plus(); break;
			}
		}
	}
};

