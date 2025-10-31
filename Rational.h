#pragma once
#include "Pair.h"

class Rational : public Pair {
public:
    
    Rational();
    Rational(double numerator, double denominator);


    double getNumerator() const;
    double getDenominator() const;
    void setNumerator(double n);
    void setDenominator(double d);


    bool operator>(const Rational& other) const;
    bool operator<(const Rational& other) const;
    bool operator==(const Rational& other) const;


    operator string() const;

    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
};


