#include "Pair.h"
#include "Rational.h"
#include <Windows.h>

Pair createPair() {
    Pair p;
    cout << "=== Створення об'єкта Pair ===" << endl;
    cin >> p;
    return p;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== Демонстрація роботи з класами Pair та Rational ===\n";

    Pair p1(3, 4);
    Pair p2(3, 5);
    cout << "p1 = " << string(p1) << ", p2 = " << string(p2) << endl;
    cout << "p1 > p2? " << (p1 > p2 ? "Так" : "Ні") << endl;

    cout << "\n=== Клас Rational ===\n";
    Rational r1(1, 2), r2(3, 4);
    cout << "r1 = " << string(r1) << ", r2 = " << string(r2) << endl;

    cout << "r1 + r2 = " << string(r1 + r2) << endl;
    cout << "r1 - r2 = " << string(r1 - r2) << endl;
    cout << "r1 > r2? " << (r1 > r2 ? "Так" : "Ні") << endl;

    cout << "\n=== Поліморфізм (принцип підстановки) ===\n";
    Pair* basePtr = new Rational(5, 7);
    cout << "Об'єкт через базовий вказівник: " << string(*basePtr) << endl;
    delete basePtr;

    cout << "\n=== Масив об'єктів ===\n";
    Rational arr[3] = { Rational(1, 2), Rational(2, 3), Rational(3, 4) };
    for (auto& r : arr)
        cout << string(r) << "  ";
    cout << endl;

    return 0;
}
