#pragma once
#include <iostream>
using namespace std;
class MyArray
{
public:
	MyArray():MyArray(3)
	{

	}
	MyArray(const size_t& size) :size{size}
	{
		this->arr = new int[size] {};
	}
	MyArray(const size_t& size, const int& value) :size{ size }
	{
		this->arr = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = rand() % value;
		}
	}
	void print() const;
	int operator[](const int& index) const; // отримали доступ за індексом на читання
	int& operator[](const int& index); // отримали доступ за індексом на запис
	MyArray operator()(const int& start, const int& end) const;
	friend const std::ostream& operator<<(ostream& out, const MyArray& data); // cout
	friend std::istream& operator>>(istream& in, MyArray& data); // cin
private:
	int* arr = nullptr;
	size_t size = 0;
};

