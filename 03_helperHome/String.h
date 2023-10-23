#pragma once
#include <iostream>
using namespace std;
class String
{
private:
	char* line = nullptr;
	void copyStr(char*& dest, const char* source);
public:
	String():String(80)
	{

	}
	String(const size_t& size)
	{
		line = new char[size + 1];
	}
	String(const char* source)
	{
		copyStr(this->line, source);
	}
	String(const String& other) { // this- clone; other - origin
		setLine(other.line);
	}
	~String()
	{
		if (this->line != nullptr) {
			delete[]line;
		}
	}
	void operator =(const String& other);
	const char* getLine() const;
	void setLine(const char* source);
};

