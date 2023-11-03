#include "MyArray.h"

void MyArray::print() const
{
    cout << "Print :: ";
    for (size_t i = 0; i < size; i++)
    {
        cout << "\t" << arr[i];
    }cout << endl;
}

int MyArray::operator[](const int& index) const
{
    if (index < 0 || index >= size) {
        cerr << "Error index !!!!" << endl;
        return arr[0];
    }
    return arr[index];
}

int& MyArray::operator[](const int& index)
{
    if (index < 0 || index >= size) {
        cerr << "Error index !!!!" << endl;
        return arr[0];
    }
    return arr[index];
}

MyArray MyArray::operator()(const int& start, const int& end) const
{
    if (start < 0 || start > size || end < 0 || end > size) {
        cout << "Error index" << endl;
        return MyArray(*this);
    }
    int start_, end_;
    if (start > end) {
        start_ = end;
        end_ = start;
    }
    else
    {
        start_ = start;
        end_ = end;
    }
    MyArray tmp(end_ - start_);
    for (size_t i = start_; i < end_; i++)
    {
        tmp[i - start_] = this->arr[i];
    }return tmp;
}

const std::ostream& operator<<(ostream& out, const MyArray& data)
{
    for (size_t i = 0; i < data.size; i++)
    {
        out << data[i] << "\t";
    }
    out << "\n";
    return out;
}

std::istream& operator>>(istream& in, MyArray& data)
{
    for (size_t i = 0; i < data.size; i++)
    {
        in >> data[i];
    }
    return in;
}
