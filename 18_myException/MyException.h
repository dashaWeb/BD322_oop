#pragma once
#include <iostream>
using namespace std;



class MyException
{
public:
	MyException(const string& message = "Unknow error", const double& value = 0)
		:message(message), value{ value }{}
	const string& what() const
	{
		return message;
	}
	const double& getValue() const
	{
		return value;
	}
private:
	string message;
	double value;
};

class DivByZeroException : public MyException
{
public:
	DivByZeroException(const string& message = "Division by zero")
		:MyException(message)
	{}
};

class TooBigDivisionException : public MyException
{
	static const int LIMIT_UP = 1'000'000;
public:
	TooBigDivisionException(const string& message = "Too big value", const double& value = LIMIT_UP)
		:MyException(message,value)
	{}
};

class TooSmallDivisionException : public MyException
{
	static const int LIMIT_DOWN = -1'000'000;
public:
	TooSmallDivisionException(const string& message = "Too big value", const double& value = LIMIT_DOWN)
		:MyException(message, value)
	{}
};