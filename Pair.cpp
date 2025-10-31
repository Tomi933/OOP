#include "Pair.h"
#include <stdexcept>


Pair::Pair() : first(0), second(0) {}

Pair::Pair(double f, double s) {
    if (!cin.good()) throw invalid_argument("Неприпустимі значення!");
    first = f;
    second = s;
}


double Pair::getFirst() const { return first; }
double Pair::getSecond() const { return second; }

void Pair::setFirst(double f) { first = f; }
void Pair::setSecond(double s) { second = s; }


bool Pair::operator>(const Pair& other) const {
    return (first > other.first) || (first == other.first && second > other.second);
}

bool Pair::operator<(const Pair& other) const {
    return (first < other.first) || (first == other.first && second < other.second);
}

bool Pair::operator==(const Pair& other) const {
    return first == other.first && second == other.second;
}


Pair::operator string() const {
    return "(" + to_string(first) + ", " + to_string(second) + ")";
}


istream& operator>>(istream& in, Pair& p) {
    cout << "Введіть перше число: ";
    in >> p.first;
    cout << "Введіть друге число: ";
    in >> p.second;
    return in;
}

ostream& operator<<(ostream& out, const Pair& p) {
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

