#pragma once
#include <iostream>
#include <string>

namespace Shape {
	double areaSquare(double side);
	const double side = 15;
	namespace Rectanle {
		const double width = 15;
		const double height = 20;
		double area(double w, double h);
	}
}

namespace StudentST {
	class Student {
		std::string name;
		int age;
	public:
		Student(std::string name, int age)
			:name(name),age(age)
		{}
		void print() const {

			std::cout << "------- Student ST-3 --------" << std::endl;
			std::cout << "Name :: " << name << std::endl;
			std::cout << "Age  :: " << age << std::endl;
		}
	};
}
namespace StudentMK {
	class Student {
		std::string name;
		int age;
	public:
		Student(std::string name, int age)
			:name(name), age(age)
		{}
		void print() const {

			std::cout << "------- Student MKA --------" << std::endl;
			std::cout << "Name :: " << name << std::endl;
			std::cout << "Age  :: " << age << std::endl;
		}
	};
}
