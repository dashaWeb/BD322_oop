#pragma once
#include <iostream>
#include <string>
using std::string;
using std::to_string;
class Fraction
{
public:
	Fraction() = default;
	Fraction(const int& num, const int& denum) :num{ num }, denum{denum}{}
	const int& getNum() const;
	const int& getDenum() const;
	void setNum(const int& num);
	void setDenum(const int& denum);
	string getFraction() const;
	Fraction operator + (const Fraction& other)const; // this(left, one); other(right, two)
	Fraction operator - (const Fraction& other)const; // this(left, one); other(right, two)
	Fraction operator * (const Fraction& other)const; // this(left, one); other(right, two)
	Fraction operator / (const Fraction& other)const; // this(left, one); other(right, two)
	Fraction operator % (int n); // this(left, one); other(right, two)
	friend std::ostream& operator<< (std::ostream & out, const Fraction & data);
private:
	int num, denum;
};

