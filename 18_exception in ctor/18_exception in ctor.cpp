#include <iostream>
using namespace std;


class Cat {

public:
    Cat(const char* name, const int& age)
    {
        try
        {
            setAge(age);
        }
        catch (const invalid_argument& ex)
        {
            this->~Cat();
            throw;
        }
    }
    ~Cat()
    {
        cout << "------- Dtor " << endl;
        if (name != nullptr)
        {
            delete[] name;
        }
    }
    void setAge(const int& age)
    {
        if (age < 0) {
            throw invalid_argument("Error:: age < 0");
        }
        this->age = age;
    }
    void setName(const char* name)
    {
        if (name != nullptr) {
            delete[] name;
        }
        size_t size = strlen(name) + 1;
        this->name = new char[size];
        strcpy_s(this->name, size, name);
    }
private :
    char* name = nullptr;
    int age = 0;
};

int main()
{
    try
    {
        Cat cat("Barsik", -2);
        cout << "Ok object created" << endl;
    }
    catch (const logic_error& ex)
    {
        cout << "Error :: " << ex.what() << endl;
    }
}
