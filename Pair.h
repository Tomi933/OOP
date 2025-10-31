#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pair {
protected:
    double first;
    double second;

public:
    
    Pair();
    Pair(double f, double s);

    
    double getFirst() const;
    double getSecond() const;
    void setFirst(double f);
    void setSecond(double s);

  
    bool operator>(const Pair& other) const;
    bool operator<(const Pair& other) const;
    bool operator==(const Pair& other) const;

  
    operator string() const;


    friend istream& operator>>(istream& in, Pair& p);
    friend ostream& operator<<(ostream& out, const Pair& p);


    virtual ~Pair() {}
};


