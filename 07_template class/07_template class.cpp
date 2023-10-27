#include <iostream>
#include "Matix.h"
using namespace std;

//template <typename T>
//T sum(T a, T b) {
//    return a + b;
//}


int main()
{
    Matrix<> mas(3);
    Matrix<double> d_mas(2.25);
    cout << "Print Array int :: \n";
    cout << mas;
    cout << "Print Array double :: \n";
    cout << d_mas;
    Matrix<> res = mas + 3;
    cout << "Print Array int + 3 :: \n";
    cout << res;
    res(0, 0) = 33;
    cout << "Element :: " << res(0, 0) << endl;
}
