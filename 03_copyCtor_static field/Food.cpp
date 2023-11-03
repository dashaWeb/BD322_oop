#include "Food.h"

void Food::strCopy(char*& dest, const char* source)
{
	// memory leak
	if (dest != nullptr) {
		delete[] dest;
	}
	dest = new char[strlen(source) + 1];
	strcpy_s(dest, strlen(source) + 1, source);
}

void Food::print() const
{
	cout << "\n\n==============="<< this->id <<"==================\n";
	cout << "\t Name   :: " << getName() << endl;
	cout << "\t kkal   :: " << getKkal() << endl;
	cout << "\t weight :: " << getWeight() << endl;
}
void Food::operator=(const Food& other)
{
	setName(other.name);
	setKkal(other.kkal);
	setWeight(other.weight);
}
size_t Food::counter = 0;