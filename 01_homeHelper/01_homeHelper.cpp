#include <iostream>
#include <string>
using namespace std;



class Fraction {
private:
    int num;
    int dnum;
public:
    Fraction(const int& num, const int& dnum)
    {
        this->num = num;
        this->dnum = dnum;
    }
    string print() {
        return to_string(this->num) + "/" + to_string(dnum);
    }
    Fraction sum(const Fraction& other) {
        // 1/3 + 4/7; dnum = 3 * 7 -> 21; num = 1 * 7 + 4 * 3 
        /*int dnum = this->dnum * other.dnum;
        int num = this->num * other.dnum + other.num * this->dnum;*/
        Fraction res(this->num * other.dnum + other.num * this->dnum, this->dnum * other.dnum);
        return res;
    }
};
int main()
{
    Fraction f_1(1, 3);
    Fraction f_2(4, 7);
    Fraction res = f_1.sum(f_2);
    cout << "Sum :: " << f_1.print() << " + " << f_2.print() << " = " << res.print() << endl;
}
