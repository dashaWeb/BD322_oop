#include <iostream>
using namespace std;


class Point
{
public:
	Point(const int& x, const int& y) :x{ x }, y{ y } {};
private:
	int x, y;
	friend void print(const Point& point, string name);
	friend void edit(Point& point);
};


void print(const Point& point, string name = "A")
{
	cout << name << "(" << point.x << "," << point.y << ")" << endl;
}
void edit(Point& point)
{
	cout << "Enter x :: ";
	cin >> point.x;
	cout << "Enter y :: ";
	cin >> point.y;
}

class Pupil;

class Teacher {
public:
	void markMath(Pupil& pupil, double mark);
	void markEnglish(Pupil& pupil, double mark);
};

class Pupil {
private:
	string name;
	double math;
	double english;
	/*friend void Teacher::markMath(Pupil& pupil, double mark);
	friend void Teacher::markEnglish(Pupil& pupil, double mark);*/
	friend class Teacher;
public:
	Pupil(string name) :name{name}
	{
		math = 0;
		english = 0;
	}
	void print() const
	{
		cout << "======= " << name << " =======\n";
		cout << "Math    :: " << math << endl;
		cout << "English :: " << english << endl;
	}
};
int main()
{
	/*Point A(5, 7);
	print(A);
	edit(A);
	print(A);*/

	Teacher teacher;
	Pupil pupil("Ivan");
	pupil.print();

	teacher.markMath(pupil, 10);
	teacher.markEnglish(pupil, 12);
	pupil.print();
}

void Teacher::markMath(Pupil& pupil, double mark)
{
	pupil.math = mark;
}

void Teacher::markEnglish(Pupil& pupil, double mark)
{
	pupil.english = mark;
}
