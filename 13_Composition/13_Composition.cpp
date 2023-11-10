#include <iostream>
using namespace std;


class Person
{
public:
	Person(string name):
		name{name}{}
	void think() {
		brain.think();
	}
	class Brain{
	public:
		void think() {
			cout << "I Think" << endl;
		}
	};
private:
	string name;
	Brain brain;
};



int main()
{
	Person ivan("Ivan");
	ivan.think();

}
