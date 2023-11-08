#pragma once
#include <iostream>
using namespace std;


template<typename T>
struct Node
{
	T data;
	Node* parent, * left, * right;
	Node(const T& data = T(), Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr):
		data{ data }, left{left}, parent{parent}, right{right}
	{

	}
};

template<typename T>
class BTree
{
public:
	BTree() = default;
	void add(const T& data);
	void print() const;
	bool isEmpty()const;
	T min() const;
	T max() const;
	bool find(const T& data) const;
private:
	Node<T>* root = nullptr;
	size_t size = 0;
	void helperPrint(Node<T>* node) const;
};

template<typename T>
inline void BTree<T>::add(const T& data)
{
	Node<T>* newNode = new Node<T>(data);
	size++;
	if (isEmpty()) {
		root = newNode;
		return;
	}
	auto tmp = root;
	while (true)
	{
		if (newNode->data < tmp->data) { // визначаємо гілку для нового значення
			if (tmp->left == nullptr) { // перевірка чи вільно
				tmp->left = newNode;
				newNode->parent = tmp;
				break;
			}
			tmp = tmp->left;
		}
		else {
			if (tmp->right == nullptr) { // перевірка чи вільно
				tmp->right = newNode;
				newNode->parent = tmp;
				break;
			}
			tmp = tmp->right;
		}
	}

}

template<typename T>
inline void BTree<T>::print() const
{
	cout << "Binary Tree :: ";
	helperPrint(root);
	cout << endl;
}

template<typename T>
inline bool BTree<T>::isEmpty() const
{
	return root == nullptr;
}

template<typename T>
inline T BTree<T>::min() const
{
	auto tmp = root;
	while (tmp->left != nullptr)
	{
		tmp = tmp->left;
	}
	return tmp->data;
}

template<typename T>
inline T BTree<T>::max() const
{
	auto tmp = root;
	while (tmp->right != nullptr)
	{
		tmp = tmp->right;
	}
	return tmp->data;
}

template<typename T>
inline bool BTree<T>::find(const T& data) const
{
	auto tmp = root;
	while (tmp != nullptr)
	{
		if (tmp->data == data) {
			return true;
		}
		if (data < tmp->data) {
			tmp = tmp->left;
		}
		else {
			tmp = tmp->right;
		}
	}
	return false;
}

template<typename T>
inline void BTree<T>::helperPrint(Node<T>* node) const
{
	if (node != nullptr) {
		helperPrint(node->left);
		cout << node->data << "\t";
		helperPrint(node->right);
	}
}
