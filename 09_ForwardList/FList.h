#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node* next;
	Node(const T& data, Node* next = nullptr) :
		data{ data }, next{ next }
	{

	}
};

template <typename T>
class FList
{
public:
	FList() = default;
	void addHead(const T& data);
	void print() const;
	bool isEmpty() const;
	void removeHead();
	size_t getSize() const;
	void clear(); // очищення вього списка
	void addTail(const T& data); // додати нову ноду в кінець списка
	// * перевантажити оператор += результат новий список, який обєднав два списка
	// * перевантажити оператор - результат новий список, який містить в собі спільні елементи обох списків без повторень
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t size = 0;

};

template<typename T>
inline void FList<T>::addHead(const T& data)
{
	Node<T>* tmp = new Node<T>(data, head);
	if (isEmpty()) {
		tail = tmp;
	}
	head = tmp;
	++size;
}

template<typename T>
inline void FList<T>::print() const
{
	auto tmp = head;
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->next;
	}
	cout << endl;
}

template<typename T>
inline bool FList<T>::isEmpty() const
{
	return head == nullptr;
}

template<typename T>
inline void FList<T>::removeHead()
{
	if (isEmpty()) {
		cout << "Firward List is empty" << endl;
		return;
	}
	auto* tmp = head; // Зберегли першу ноду
	head = head->next; // Змістили head до наступної ноди
	if (isEmpty()) {
		tail = nullptr;
	}
	delete tmp; // видалили ноду
	--size;

}

template<typename T>
inline size_t FList<T>::getSize() const
{
	return size;
}
