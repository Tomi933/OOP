#include <iostream>
#include <Windows.h>
#include "Book.h"
using namespace std;


void printAll(Book* books, int count) {
    cout << "\n������ ����:\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". ";
        books[i].print();
    }
}


void addBook(Book*& books, int& count) {
    string t, a;
    int y, p;
    cout << "\n������ �����: ";
    cin.ignore();
    getline(cin, t);
    cout << "�����: ";
    getline(cin, a);
    cout << "г�: ";
    cin >> y;
    cout << "�������: ";
    cin >> p;

    int newCount = count + 1;
    Book* newBooks = new Book[newCount];

    for (int i = 0; i < count; i++)
        newBooks[i] = books[i];

    newBooks[newCount - 1] = Book(t, a, y, p);

    delete[] books;

    books = newBooks;
    count = newCount;

    cout << "����� ������!\n";
}


void removeBook(Book*& books, int& count) {
    if (count == 0) {
        cout << "������ �������!\n";
        return;
    }

    int index;
    cout << "\n������ ����� ����� ��� ��������� (1-" << count << "): ";
    cin >> index;

    if (index < 1 || index > count) {
        cout << "����������� �����!\n";
        return;
    }

    int newCount = count - 1;
    Book* newBooks = new Book[newCount];

    for (int i = 0, j = 0; i < count; i++) {
        if (i != index - 1)
            newBooks[j++] = books[i];
    }

    delete[] books;
    books = newBooks;
    count = newCount;

    cout << "����� ��������!\n";
}


void sortByYear(Book* books, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (books[j].getYear() > books[j + 1].getYear()) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
    cout << "³���������� �� ����� �������!\n";
}

void sortByPages(Book* books, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (books[j].getPages() > books[j + 1].getPages()) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
    cout << "³���������� �� ������� �������!\n";
}

void showByAuthor(Book* books, int count) {
    string author;
    cout << "\n������ ������: ";
    cin.ignore();
    getline(cin, author);
    cout << "\n����� ������ " << author << ":\n";

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (books[i].getAuthor() == author) {
            books[i].print();
            found = true;
        }
    }

    if (!found)
        cout << "���� ����� ������ �� ��������.\n";
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int count = 5;
    Book* books = new Book[count]{
        Book("������� � ���������", "�. ��������", 1966, 480),
        Book("������", "�. ��������", 1840, 300),
        Book("1984", "��. ������", 1949, 328),
        Book("����� ����", "��. ������", 1909, 520),
        Book("��� ���� ���������", "�. ����� ������", 1967, 410)
    };

    int choice;
    do {
        cout << "\n=== ���� ===\n"
            << "1. �������� �� �����\n"
            << "2. ������ �����\n"
            << "3. �������� �����\n"
            << "4. ��������� �� �����\n"
            << "5. ��������� �� ���������\n"
            << "6. �������� ����� ������� ������\n"
            << "0. �����\n"
            << "��� ����: ";
        cin >> choice;

        switch (choice) {
        case 1: printAll(books, count); break;
        case 2: addBook(books, count); break;
        case 3: removeBook(books, count); break;
        case 4: sortByYear(books, count); break;
        case 5: sortByPages(books, count); break;
        case 6: showByAuthor(books, count); break;
        case 0: cout << "�����...\n"; break;
        default: cout << "������� ����!\n";
        }
    } while (choice != 0);

    delete[] books;
    return 0;
}
