#pragma once
#include "Man.h"

class Student {
private:
    Man man;
    int course;

public:
   
    Man getMan() const { return man; }
    int getCourse() const { return course; }

  
    void setMan(Man man) { this->man = man; }
    void setCourse(int course) { this->course = course; }

   
    void IncreaseCourse() { ++course; }

    void Init(Man man, int course);
    void Display() const;
    void Read();

    Student(Man man = Man(), int course = 1);
    Student(const Student& s);
    Student& operator = (const Student& s);

    friend ostream& operator << (ostream& out, const Student& s);
    friend istream& operator >> (istream& in, Student& s);

    operator string () const;

    ~Student();
};
