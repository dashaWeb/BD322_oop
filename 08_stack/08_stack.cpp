#include <iostream>
#include <tuple>
#include <initializer_list>
#include "Stack.h"
using namespace std;


auto maxValue(int arr[][3], int row, int col) {
    int max = arr[0][0];
    int r = 0, c = 0;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            if (max < arr[i][j]) {
                max = arr[i][j];
                r = i;
                c = j;
            }
        }
    }
    return pair<int,int>(r,c);
}

int main()
{

    int arr[3][3]{
        {1,5,8},
        {9,6,2},
        {6,7,5},
    };

    auto res = maxValue(arr, 3, 3);
    cout << "index row :: " << res.first << "; index col :: " << res.second << endl;

    initializer_list<int> data{ 2,5,8,9,6,5,4 };
    /*for (size_t i = 0; i < data.size(); i++)
    {
        cout << data.begin()[i] << "\t";
    }
    cout << endl;*/


    /*for (auto ptr = data.begin(); ptr != data.end(); ptr++)
    {
        cout << *ptr << "\t";
    }
    cout << endl;*/

    for (auto& item : data)
    {
        cout << item << "\t";
    }cout << endl;

    /*tuple<int, double, string> data(2, 3.6, "Text");
    cout << get<0>(data) << endl;
    cout << get<1>(data) << endl;
    cout << get<2>(data) << endl;*/

   /* Stack<> one(5,2);
    cout << one.top() << endl;
    one.push(22);
    one.push(33);
    one.push(44);
    cout << one.top() << endl;
    cout << "Size     :: " << one.size() << endl;
    cout << "Capacity :: " << one.getCapacity() << endl;
    one.push(44);
    cout << "\n===============\n" << endl;
    cout << "Push" << one.top() << endl;
    cout << "Size     :: " << one.size() << endl;
    cout << "Capacity :: " << one.getCapacity() << endl;
    one.push(17);
    cout << "\n===============\n" << endl;
    cout << "Push" << one.top() << endl;
    cout << "Size     :: " << one.size() << endl;
    cout << "Capacity :: " << one.getCapacity() << endl;
    one.push(11);
    cout << "\n===============\n" << endl;
    cout << "Push" << one.top() << endl;
    cout << "Size     :: " << one.size() << endl;
    cout << "Capacity :: " << one.getCapacity() << endl;
    one.push(11);
    cout << "\n===============\n" << endl;
    cout << "Push" << one.top() << endl;
    cout << "Size     :: " << one.size() << endl;
    cout << "Capacity :: " << one.getCapacity() << endl;
    one.push(11);
    cout << "\n===============\n" << endl;
    cout << "Push" << one.top() << endl;
    cout << "Size     :: " << one.size() << endl;
    cout << "Capacity :: " << one.getCapacity() << endl;
    one.push(11);
    cout << "\n===============\n" << endl;
    cout << "Push" << one.top() << endl;
    cout << "Size     :: " << one.size() << endl;
    cout << "Capacity :: " << one.getCapacity() << endl;
    one.push(11);
    cout << "\n===============\n" << endl;
    cout << "Push" << one.top() << endl;
    cout << "Size     :: " << one.size() << endl;
    cout << "Capacity :: " << one.getCapacity() << endl;
    one.push(11);
    cout << "\n===============\n" << endl;
    cout << "Push" << one.top() << endl;
    cout << "Size     :: " << one.size() << endl;
    cout << "Capacity :: " << one.getCapacity() << endl;
    one.push(11);
    cout << "\n===============\n" << endl;
    cout << "Push" << one.top() << endl;
    cout << "Size     :: " << one.size() << endl;
    cout << "Capacity :: " << one.getCapacity() << endl;
    one.push(11);
    cout << "\n===============\n" << endl;
    cout << "Push" << one.top() << endl;
    cout << "Size     :: " << one.size() << endl;
    cout << "Capacity :: " << one.getCapacity() << endl;
    one.push(11);
    cout << "\n===============\n" << endl;
    cout << "Push" << one.top() << endl;
    cout << "Size     :: " << one.size() << endl;
    cout << "Capacity :: " << one.getCapacity() << endl;*/
    
}
