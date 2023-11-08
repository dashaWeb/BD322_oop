#include <iostream>
#include "BTree.h"
using namespace std;

int main()
{
    BTree<int> tree;
    tree.add(50);
    tree.add(45);
    tree.add(60);
    tree.add(44);
    tree.add(46);
    tree.print();

    cout << "Min :: " << tree.min() << endl;
    cout << "Max :: " << tree.max() << endl;
    cout << "Find 46 :: " << boolalpha << tree.find(46) << endl;
    cout << "Find 77 :: " << boolalpha << tree.find(77) << endl;
}
