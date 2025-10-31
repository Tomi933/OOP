#include "Rational.h"
#include <stdexcept>
#include <sstream>

Rational::Rational() : Pair(0, 1) {}

Rational::Rational(double numerator, double denominator) : Pair(numerator, denominator) {
    if (denominator == 0) {
        cerr << "Помилка: знаменник не може бути 0!" << endl;
        exit(1);
    }
}


double Rational::getNumerator() const { return first; }
double Rational::getDenominator() const { return second; }

void Rational::setNumerator(double n) { first = n; }
void Rational::setDenominator(double d) {
    if (d == 0) {
        cerr << "Помилка: знаменник не може бути 0!" << endl;
        exit(1);
    }
    second = d;
}


Rational Rational::operator+(const Rational& other) const {
    double n = first * other.second + other.first * second;
    double d = second * other.second;
    return Rational(n, d);
}

Rational Rational::operator-(const Rational& other) const {
    double n = first * other.second - other.first * second;
    double d = second * other.second;
    return Rational(n, d);
}


bool Rational::operator>(const Rational& other) const {
    return first / second > other.first / other.second;
}
bool Rational::operator<(const Rational& other) const {
    return first / second < other.first / other.second;
}
bool Rational::operator==(const Rational& other) const {
    return first / second == other.first / other.second;
}

Rational::operator string() const {
    ostringstream out;
    out << first << "/" << second;
    return out.str();
}

