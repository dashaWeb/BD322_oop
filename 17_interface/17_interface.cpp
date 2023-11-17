#include <iostream>
#include <conio.h>
using namespace std;

// _interface
// interface => задає поведінку для класів, які його реалізовують. Мітить лише число віртуальні методи

struct IMove {
    virtual void move() const = 0;
    virtual double getSpeed() const = 0;
};

struct IFly : IMove
{
    virtual void fly() const = 0;
    virtual double getHeight() const = 0;
};

class Bird : IFly {
    double speed, height;
public:
    Bird(const double& speed, const double& height)
        :speed{ speed }, height{height}
    {

    }
    virtual void move() const override;
    virtual void fly() const override;
    virtual double getSpeed() const override;
    virtual double getHeight() const override;
};

class Car : IMove
{
    double speed;
    string brand;
public:
    Car(const string& brand, const double& speed)
        :brand{brand},speed{speed}
    {

    }
    void move() const override;
    double getSpeed() const override;
};
class Plane : IFly
{
    double speed, height;
    string brand;
public:
    Plane(const string& brand, const double& speed, const double& height)
        :brand{brand}, speed{speed}, height{height}
    {

    }
    virtual void move() const override;
    virtual void fly() const override;
    virtual double getSpeed() const override;
    virtual double getHeight() const override;
};
class Owner
{
    string name;
    IMove* item = nullptr;
public:
    Owner(const string& name, IMove* item)
        :name{name},item{item}
    {

    }
    void print() const
    {
        item->move();
        cout << "Speed :: " << item->getSpeed() << endl;
        auto s = dynamic_cast<IFly*>(item);
        if (s != nullptr) {
            s->fly();
            cout << "Height :: " << s->getHeight();
        }
    }
};



// way
__interface IShape
{
    double getArea() const;
};

class Rectangle :public IShape
{
    double width, height;
public:
    Rectangle(const double& width, const double& height)
        :width{width}, height{height}
    {

    }
    double getArea() const
    {
        return width * height;
    }
};
class Square : public Rectangle
{
public:
    Square(const double& side)  
        :Rectangle(side, side)
    {

    }
};
class Circle : public IShape
{
    double radius;
public:
    Circle(const double& radius)
        :radius{radius}
    {

    }
    double getArea() const
    {
        return pow(radius, 2) * 3.14;
    }
};
int main()
{
    char s;
    do
    {
        s = _getch();
        cout << s << " \t " << (int)s << endl;
    } while (s != 27);
    

   /* Rectangle shape_1(10, 15);
    cout << "Rectangle :: " << shape_1.getArea() << endl;
    Square shape_2(5);
    cout << "Square :: " << shape_2.getArea() << endl;
    Circle circle(10);
    cout << "Circle :: " << circle.getArea() << endl;

    IShape* shapes[]{&shape_1,&shape_2,&circle};
    for (size_t i = 0; i < 3; i++)
    {
        cout << typeid(shapes[i]).name() << " \t " << shapes[i]->getArea() << endl;
    }*/


    /*Bird bird(50, 100);
    bird.move();
    bird.fly();
    cout << "Speed :: " << bird.getSpeed() << endl;
    cout << "Height :: " << bird.getHeight() << endl;

    Car ford("Ford", 150);
    ford.move();
    cout << "Speed :: " << ford.getSpeed() << endl;

    Plane plane("CT-12", 300, 500);
    plane.move();
    plane.fly();
    cout << "Speed :: " << plane.getSpeed() << endl;
    cout << "Height :: " << plane.getHeight() << endl;
    Owner ownerCar("Denis", (IMove*)&ford);
    ownerCar.print();

    Owner ownerPlane("Vlad", (IMove*)&plane);
    ownerPlane.print();*/

}
    

void Bird::move() const
{
    cout << "I Move :: " << typeid(*this).name() << endl;
}

void Bird::fly() const
{
    cout << "I Fly :: " << typeid(*this).name() << endl;
}

double Bird::getSpeed() const
{
    return speed;
}

double Bird::getHeight() const
{
    return height;
}

void Car::move() const
{
    cout << brand << " Move :: " << typeid(*this).name() << endl;
}

double Car::getSpeed() const
{
    return speed;
}

void Plane::move() const
{
    cout << brand << " Move :: " << typeid(*this).name() << endl;
}

void Plane::fly() const
{
    cout << brand << " Fly :: " << typeid(*this).name() << endl;
}

double Plane::getSpeed() const
{
    return speed;
}

double Plane::getHeight() const
{
    return height;
}
