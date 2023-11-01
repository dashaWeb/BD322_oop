#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct Node
{
	int pr;
	T data;
	Node(const T& data = T(), const int& pr = 0) :
		data{ data }, pr{ pr }
	{

	}
};

template <typename T = int>
class PrQueue
{
public:
	PrQueue(const size_t& size, const size_t& step) :
		capacity{ size }, step{ step }, back_{ -1 }
	{
		queue = new Node<T>[capacity];
	}
	void empty(); // очищення стеку
	void push(const Node<T>& data); // додати нове значення в стек
	void pop(); // видалити значення
	size_t getCapacity() const;
	size_t size() const;
	const T& top();
	void print() const;
	~PrQueue()
	{
		delete[] queue;
	}
private:
	Node<T>* queue = nullptr;
	bool full() const;
	void resize();
	bool isEmpty() const;
	int getPos(const Node<T> data) const;
	size_t capacity;
	size_t step;
	int back_;
};

template<typename T>
inline void PrQueue<T>::empty()
{
	back_ = -1;
}

template<typename T>
inline void PrQueue<T>::push(const Node<T>& data)
{
	back_++;
	int index = getPos(data);
	if (full()) {
		resize();
	}
	if (isEmpty() || index == -1) {
		queue[back_] = data;
		return;
	}
	for (int i = back_; i > index; i--)
	{
		queue[i] = queue[i - 1];
	}
	queue[index] = data;
}

template<typename T>
inline void PrQueue<T>::pop()
{
}

template<typename T>
inline size_t PrQueue<T>::getCapacity() const
{
	return this->capacity;
}

template<typename T>
inline size_t PrQueue<T>::size() const
{
	return back_ + 1;
}

template<typename T>
inline const T& PrQueue<T>::top()
{
	if (back_ == -1) {
		return T();
	}
	return queue[0];
}

template<typename T>
inline void PrQueue<T>::print() const
{
	if (isEmpty()) {
		cout << "Queue is empty" << endl;
		return;
	}
	for (size_t i = 0; i <= back_; i++)
	{
		cout << queue[i].data << "(" << queue[i].pr << ")" << "\t";
	}
	cout << endl;

}

template<typename T>
inline bool PrQueue<T>::full() const
{
	return capacity == back_;
}

template<typename T>
inline void PrQueue<T>::resize()
{
	capacity += step;
	step *= 2;
	Node<T>* tmp = new Node<T>[capacity];
	for (size_t i = 0; i <= back_; i++)
	{
		tmp[i] = queue[i];
	}

}

template<typename T>
inline bool PrQueue<T>::isEmpty() const
{
	return back_ == -1;
}

template<typename T>
inline int PrQueue<T>::getPos(const Node<T> data) const
{
	for (size_t i = 0; i < back_; i++)
	{
		if (data.pr > queue[i].pr) {
			return i;
		}
	}
	return -1;
}
