#include <iostream>
using namespace std;

enum Colors{RED,GREEN,BLUE};

class Point {
public:
    int x = 0, y = 0;
    virtual void print() const {
        cout << "(" << x << "," << y << ")" << endl;
    }
};
class Point3D: public Point
{
public:
    int z = 0;
    void print() const override
    {
        cout << "(" << x << "," << y << "," << z << ")" << endl;
    }
};

class String
{
public:
    string str;
};
int main()
{
    int a = 32768; // 4 bytes
    unsigned char s = a; // -128 - 127
    short aa = a;
    // 0 1 2 3 4 5 .... 255
    cout << "(int) " << a << "\t size :: " << sizeof(int) << endl;
    cout << "(char) " << (int)s << "\t size :: " << sizeof(char) << endl;
    cout << "(short) " << aa << "\t size :: " << sizeof(char) << endl;
    cout << (int)Colors::RED << endl;

    Point point_;
    point_.x = 1;
    point_.y = 2;


    //String str = (String&)point_; // ?? not error

    // static_cast

    cout << "\n________ STATIC_CAST__________\n";
    cout << "static_cast<char>(122) :: " << static_cast<char>(122) << endl;
    cout << "static_cast<int>(Colors::GREEN) :: " << static_cast<int>(Colors::GREEN) << endl;
    cout << "static_cast<Colors>(3) :: " << static_cast<Colors>(3) << endl;
    Colors color = static_cast<Colors>(3);

    Point3D point3d;
    point3d.x = 2;
    point3d.y = 5;
    point3d.z = 7;

    Point& point = point3d;
    /*point.print();*/

    /*Point3D points = (Point3D&)point;
    points.print();*/

    if (typeid(point) == typeid(Point3D)){
        Point3D res = static_cast<Point3D&>(point);
        res.print();
    }
    else {
        cout << "Untenable casting" << endl;
    }
    if (typeid(point3d) == typeid(Point)) {
        Point res = static_cast<Point&>(point3d);
        res.print();
    }
    else {
        cout << "Untenable casting" << endl;
    }
}
