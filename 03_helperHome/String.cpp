#include "String.h"

void String::copyStr(char*& dest, const char* source)
{
	if (dest != nullptr) {
		delete[] dest;
	}
	dest = new char[strlen(source) + 1];
	strcpy_s(dest, strlen(source) + 1, source);
}

void String::operator=(const String& other)
{
	if (this == &other) {
		return;
	}
	setLine(other.line);
}

const char* String::getLine() const
{
	return this->line;
}

void String::setLine(const char* source)
{
	copyStr(this->line, source);
}
