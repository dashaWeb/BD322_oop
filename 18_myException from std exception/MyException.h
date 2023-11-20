#pragma once
#include <iostream>
using namespace std;

class DivByZeroException : public exception
{
public:
	DivByZeroException(const string& message = "Division by zero")
		:exception(message.data())
	{}
};


class TooBigDivisionException : public overflow_error
{
	static const int LIMIT_UP = 1'000'000;
	double value;
public:
	TooBigDivisionException(const string& message = "Too big value", const double& value = LIMIT_UP)
		:overflow_error(message), value(value)
	{}
	const double& getValue() const {
		return value;
	}
};

class TooSmallDivisionException : public underflow_error
{
	static const int LIMIT_DOWN = -1'000'000;
	double value;

public:
	TooSmallDivisionException(const string& message = "Too big value", const double& value = LIMIT_DOWN)
		:underflow_error(message), value(value)
	{}
	const double& getValue() const {
		return value;
	}
};
