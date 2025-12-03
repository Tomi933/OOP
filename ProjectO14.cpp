#include <iostream>
#include <vector>
#include <forward_list>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

//Завдання 1

void fillVector(vector<int>& v, int n) {
    srand(time(0));
    v.resize(n);
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 41 - 20; 
    }
}

void printVector(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

bool findMinEven(const vector<int>& v, int& result) {
    bool found = false;

    for (int x : v) {
        if (x % 2 == 0) {  
            if (!found || x < result) {
                result = x;
                found = true;
            }
        }
    }

    return found;
}

//Завдання 2

void fillList(forward_list<int>& lst, int n) {
    srand(time(0));

    for (int i = 0; i < n; i++) {
        int value = rand() % 41 - 20;
        lst.push_front(value);
    }

    lst.reverse();
}

void printList(const forward_list<int>& lst) {
    for (int x : lst)
        cout << x << " ";
    cout << endl;
}

int sumNegativeEven(const forward_list<int>& lst) {
    int sum = 0;

    for (int x : lst) {
        if (x < 0 && x % 2 == 0)
            sum += x;
    }
    return sum;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введіть розмір вектора: ";
    cin >> n;

    vector<int> v;
    fillVector(v, n);

    cout << "Вектор: ";
    printVector(v);

    int minEven;
    if (findMinEven(v, minEven))
        cout << "Найменший парний елемент: " << minEven << endl;
    else
        cout << "Парних елементів немає." << endl;

    // 2

    int k = 0;
    cout << "Введіть кількість елементів списку: ";
    cin >> k;

    forward_list<int> lst;

    fillList(lst, k);

    cout << "Список: ";
    printList(lst);

    int result = sumNegativeEven(lst);
    cout << "Сума від’ємних парних елементів: " << result << endl;

    return 0;
}
