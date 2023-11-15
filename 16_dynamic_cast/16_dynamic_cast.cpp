#include <iostream>
#include <vector>
using namespace std;


class Person {
private:
    string name = "NoName";
    size_t counter = 0;
public:
    Person() = default;
    Person(const string& name) 
    {
        setName(name);
    }
    void setName(const string& name) {
        if (!name.empty()) {
            this->name = name;
        }
    }
    string getName() const {
        return this->name;
    }
    virtual void print() const
    {
        cout << "Name :: " << name << endl;
    }
};

class Student : public Person
{
    string specialization = "No spec";
public:
    Student(const string& name,const string& spec)
        :Person(name)
    {
        setSpec(spec);
    }
    void setSpec(const string& spec) {
        if (!spec.empty()) {
            this->specialization = spec;
        }
    }
    virtual void learn() {
        cout << typeid(*this).name() << " \t studs :: " << specialization << endl;
    }
    virtual void print() const override
    {
        cout << typeid(*this).name() << " \t studs :: " << specialization << endl;
        Person::print();
    }
};

class Aspirant : public Student
{
    string theme = "Important theme";
public:
    Aspirant() = default;
    Aspirant(const string& name, const string& spec,const string& theme)
        :Student(name,spec)
    {
        setTheme(theme);
    }
    void setTheme(const string& theme) {
        if (!theme.empty()) {
            this->theme = theme;
        }
    }
    virtual void print() const override
    {
        Student::print();
        cout << "Theme " << theme << endl;
    }
    virtual void writeDyplom()
    {
        cout << "Scientic theme :: " << theme << endl;
    }
};



int main()
{
    Person ann("Ann");
    Student ivan("Ivan", "Design");
    Aspirant matviy("Matviy", "CS", "AI");

    ivan.print();
    cout << endl;
    matviy.print();
    cout << endl;

    Person* person = &ivan;
    person->print();

    cout << "---------- DYNAMIC_CAST ------------" << endl;
    Student* s = dynamic_cast<Student*>(person);
    if (s == nullptr) {
        cout << "Untenable cast " << endl;
    }
    else {
        s->learn();
    }

    Aspirant* a = dynamic_cast<Aspirant*>(person);
    if (a == nullptr) {
        cout << "Untenable cast " << endl;
    }
    else {
        a->writeDyplom();
    }

    vector<Person*> people{&ann, &ivan, &matviy};
    for (auto& p : people)
    {
        cout << "\n----------------------\n";
        p->print();
        auto st = dynamic_cast<Student*>(p);
        if (st != nullptr) {
            st->learn();
        }
        auto as = dynamic_cast<Aspirant*>(p);
        if (as != nullptr) {
            as->writeDyplom();
        }
        cout << "\n----------------------\n";
    }
}
