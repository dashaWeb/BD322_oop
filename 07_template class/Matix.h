#pragma once
#include <iostream>
using namespace std;


template<typename T = int, int rows = 3, int cols = 4>
class Matrix
{
public:
	Matrix() = default;
	Matrix(const T& value);

	template<typename T = int, int rows, int cols>
	friend ostream& operator <<(ostream& out, const Matrix<T,rows,cols>& data);
	Matrix<T, rows, cols> operator+(const T& value) const;
	T& operator()(const size_t& i, const size_t& j);
private:
	T arr[rows][cols];
};

template<typename T, int rows, int cols>
inline Matrix<T, rows, cols>::Matrix(const T& value)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			arr[i][j] = value;
		}
	}
}

template<typename T, int rows, int cols>
inline Matrix<T, rows, cols> Matrix<T, rows, cols>::operator+(const T& value) const
{
	Matrix<T, rows, cols>tmp(*this);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			tmp.arr[i][j] += value;
		}
	}
	return tmp;
}

template<typename T, int rows, int cols>
inline T& Matrix<T, rows, cols>::operator()(const size_t& i, const size_t& j)
{
	return arr[i][j];
}

template<typename T, int rows, int cols>
inline ostream& operator<<(ostream& out, const Matrix<T, rows, cols>& data)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			out << data.arr[i][j] << "\t";
		}
		out << "\n";
	}
	return out;
}
