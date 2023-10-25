#include "Fraction.h"

const int& Fraction::getNum() const
{
    return this->num;
}

const int& Fraction::getDenum() const
{
    return denum;
}

void Fraction::setNum(const int& num)
{
    if (num == 0) {
        return;
    }
    this->num = num;
}

void Fraction::setDenum(const int& denum)
{
    if (denum == 0) {
        return;
    }
    this->denum = denum;
}

string Fraction::getFraction() const
{
    return to_string(num) + "/" + to_string(denum);
}
Fraction Fraction::operator+(const Fraction& other)const
{
    if (this->denum == other.denum) {
        //int num = this->num + other.num;
        return Fraction(this->num + other.num,this->denum);
    }
   /* int num = this->num * other.denum + other.num * this->denum;
    int denum = this->denum * other.denum;*/
    return Fraction(this->num * other.denum + other.num * this->denum, this->denum * other.denum);

}
Fraction Fraction::operator-(const Fraction& other)const
{
    return Fraction();
}
Fraction Fraction::operator*(const Fraction& other)const
{
    return Fraction();
}
Fraction Fraction::operator/(const Fraction& other)const
{
    return Fraction();
}
Fraction Fraction::operator%(int n)
{
    Fraction tmp(*this);
    int end = (tmp.num < tmp.denum ? tmp.num : tmp.denum);
    for (int i = end; i > 1; i--)
    {
        if (tmp.num % i == 0 && tmp.denum % i == 0) {
            tmp.num /= i;
            tmp.denum /= i;
            i = tmp.num;
        }
    }
    return tmp;
}
// 1/5
