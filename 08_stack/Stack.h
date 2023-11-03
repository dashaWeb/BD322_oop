#pragma once
#include <iostream>

using namespace std;
template <typename T = int>
class Stack
{
public:
	Stack(const size_t& size, const size_t& step) :
		capacity{ size }, step{ step }, top_{ -1 }
	{
		stack = new T[capacity];
	}
	void empty(); // очищення стеку
	void push(const T& data); // додати нове значення в стек
	void pop(); // видалити значення
	size_t getCapacity() const;
	size_t size() const;
	const T& top();
	~Stack()
	{
		delete[] stack;
	}
private:
	T* stack = nullptr;
	bool full() const;
	void resize();
	size_t capacity;
	size_t counter = 4;
	size_t step;
	int top_;
};

template<typename T>
inline void Stack<T>::empty()
{
	top_ = -1;
}

template<typename T>
inline void Stack<T>::push(const T& data)
{
	top_++;
	if (full()) {
		resize();
	}
	stack[top_] = data;
}

template<typename T>
inline void Stack<T>::pop()
{
	top_--;
}

template<typename T>
inline size_t Stack<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
inline size_t Stack<T>::size() const
{
	return top_ + 1;
}

template<typename T>
const inline T& Stack<T>::top()
{
	if (top_ == -1) {
		cout << "Stack is empty" << endl;
		return T();
	}
	return stack[top_];
}

template<typename T>
inline bool Stack<T>::full() const
{
	return top_ == capacity;
}

template<typename T>
inline void Stack<T>::resize()
{
	counter *= step;
	capacity += counter;
	T* tmp = new T[capacity];
	for (size_t i = 0; i < top_; i++)
	{
		tmp[i] = stack[i];
	}
	delete[] stack;
	stack = tmp;
}
