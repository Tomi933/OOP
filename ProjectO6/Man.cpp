#include "Man.h"
#include <sstream>

void Man::Init(string name, int age, string gender, double weight) {
    setName(name);
    setAge(age);
    setGender(gender);
    setWeight(weight);
}

void Man::Display() const {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Weight: " << weight << " kg" << endl;
}

void Man::Read() {
    string name, gender;
    int age;
    double weight;

    cout << "Enter name: "; cin >> name;
    cout << "Enter age: "; cin >> age;
    cout << "Enter gender: "; cin >> gender;
    cout << "Enter weight (kg): "; cin >> weight;

    Init(name, age, gender, weight);
}

Man::Man() : name(""), age(0), gender(""), weight(0.0) {}

Man::Man(string name, int age, string gender, double weight)
    : name(name), age(age), gender(gender), weight(weight) {
}

Man::Man(const Man& m)
    : name(m.name), age(m.age), gender(m.gender), weight(m.weight) {
}

Man& Man::operator=(const Man& m) {
    if (this != &m) {
        name = m.name;
        age = m.age;
        gender = m.gender;
        weight = m.weight;
    }
    return *this;
}

ostream& operator << (ostream& out, const Man& m) {
    out << string(m);
    return out;
}

istream& operator >> (istream& in, Man& m) {
    string name, gender;
    int age;
    double weight;

    cout << "Enter name: "; in >> name;
    cout << "Enter age: "; in >> age;
    cout << "Enter gender: "; in >> gender;
    cout << "Enter weight: "; in >> weight;

    m.Init(name, age, gender, weight);
    return in;
}

Man::operator string () const {
    stringstream ss;
    ss << "Name: " << name << endl;
    ss << "Age: " << age << endl;
    ss << "Gender: " << gender << endl;
    ss << "Weight: " << weight << " kg" << endl;
    return ss.str();
}

Man::~Man() {}

