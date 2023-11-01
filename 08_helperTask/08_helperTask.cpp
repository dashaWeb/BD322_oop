#include <iostream>
#include "PrQueue.h"
using namespace std;
int main()
{
	PrQueue<int> box(5,2);
	Node<int> node_1(25, 5);
	Node<int> node_2(33, 7);
	Node<int> node_3(4, 3);
	Node<int> node_4(22, 6);
	box.print();
	box.push(node_1);
	box.push(node_2);
	box.push(node_3);
	box.push(node_4);
	box.print();
}
