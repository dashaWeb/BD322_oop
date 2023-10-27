#include <iostream>
#include "MyArray.h"
using namespace std;

int main()
{
    MyArray arr(10, 20);
    arr.print();
    cout << "Element index [0] --> " << arr[0] << endl;
    arr[0] = 33;
    arr.print();
    cout << "Element index [0] --> " << arr[0] << endl;
    MyArray array_slice = arr(1, 5);
    array_slice.print();
    cout << array_slice;
    cin >> array_slice;
    array_slice.print();


}

