#include "TV.h"

void TV::power()
{
	start = !start;
	showInfo();
}

void TV::plus()
{
	if (volume < MAX_VOLUME) {
		volume++;
	}
	showInfo();

}

void TV::minus()
{
	if (volume > 0) {
		volume--;
	}
	showInfo();

}

void TV::next()
{
	channel++;
	if (channel > max_channels) {
		channel = 1;
	}
	showInfo();

}

void TV::prev()
{
	channel--;
	if (channel < 1) {
		channel = max_channels;
	}
	showInfo();

}

void TV::showInfo()
{
	if (!start) {
		cout << "TV is turned off" << endl;
		return;
	}
	cout << "\nTV is enabled" << endl;
	cout << "Volume  :: " << volume << endl;
	cout << "Channel :: " << channel << endl;


}
