#pragma once
#include <string>
#include <iostream>
using namespace std;

class Man {
private:
    string name;
    int age;
    string gender;
    double weight;

public:

    string getName() const { return name; }
    int getAge() const { return age; }
    string getGender() const { return gender; }
    double getWeight() const { return weight; }

    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setGender(string gender) { this->gender = gender; }
    void setWeight(double weight) { this->weight = weight; }

    void Init(string name, int age, string gender, double weight);
    void Display() const;
    void Read();

    Man();
    Man(string name, int age, string gender, double weight);
    Man(const Man& m);
    Man& operator = (const Man& m);

    friend ostream& operator << (ostream& out, const Man& m);
    friend istream& operator >> (istream& in, Man& m);

    operator string () const;

    ~Man();
};
