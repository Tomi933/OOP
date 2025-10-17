#include "Student.h"
#include <sstream>

void Student::Init(Man man, int course) {
    setMan(man);
    setCourse(course);
}

void Student::Display() const {
    cout << "Student Info:" << endl;
    man.Display();
    cout << "Course: " << course << endl;
}

void Student::Read() {
    Man m;
    int course;

    cout << "--- Enter Man Info ---" << endl;
    m.Read();
    cout << "Enter course: "; cin >> course;

    Init(m, course);
}

Student::Student(Man man, int course)
    : man(man), course(course) {
}

Student::Student(const Student& s)
    : man(s.man), course(s.course) {
}

Student& Student::operator=(const Student& s) {
    if (this != &s) {
        man = s.man;
        course = s.course;
    }
    return *this;
}

ostream& operator<<(ostream& out, const Student& s) {
    out << string(s);
    return out;
}

istream& operator>>(istream& in, Student& s) {
    cout << "--- Input Student ---" << endl;
    in >> s.man;
    cout << "Enter course: "; in >> s.course;
    return in;
}

Student::operator string() const {
    stringstream ss;
    ss << string(man);
    ss << "Course: " << course << endl;
    return ss.str();
}

Student::~Student() {}
