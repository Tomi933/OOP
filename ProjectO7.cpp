#include <iostream>
#include <Windows.h>
#include "Book.h"
using namespace std;


void printAll(Book* books, int count) {
    cout << "\nСписок книг:\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". ";
        books[i].print();
    }
}


void addBook(Book*& books, int& count) {
    string t, a;
    int y, p;
    cout << "\nВведіть назву: ";
    cin.ignore();
    getline(cin, t);
    cout << "Автор: ";
    getline(cin, a);
    cout << "Рік: ";
    cin >> y;
    cout << "Сторінок: ";
    cin >> p;

    int newCount = count + 1;
    Book* newBooks = new Book[newCount];

    for (int i = 0; i < count; i++)
        newBooks[i] = books[i];

    newBooks[newCount - 1] = Book(t, a, y, p);

    delete[] books;

    books = newBooks;
    count = newCount;

    cout << "Книгу додано!\n";
}


void removeBook(Book*& books, int& count) {
    if (count == 0) {
        cout << "Список порожній!\n";
        return;
    }

    int index;
    cout << "\nВведіть номер книги для видалення (1-" << count << "): ";
    cin >> index;

    if (index < 1 || index > count) {
        cout << "Некоректний номер!\n";
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

    cout << "Книгу видалено!\n";
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
    cout << "Відсортовано за роком видання!\n";
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
    cout << "Відсортовано за кількістю сторінок!\n";
}

void showByAuthor(Book* books, int count) {
    string author;
    cout << "\nВведіть автора: ";
    cin.ignore();
    getline(cin, author);
    cout << "\nКниги автора " << author << ":\n";

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (books[i].getAuthor() == author) {
            books[i].print();
            found = true;
        }
    }

    if (!found)
        cout << "Книг цього автора не знайдено.\n";
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int count = 5;
    Book* books = new Book[count]{
        Book("Майстер і Маргарита", "М. Булгаков", 1966, 480),
        Book("Кобзар", "Т. Шевченко", 1840, 300),
        Book("1984", "Дж. Орвелл", 1949, 328),
        Book("Мартін Іден", "Дж. Лондон", 1909, 520),
        Book("Сто років самотності", "Г. Гарсія Маркес", 1967, 410)
    };

    int choice;
    do {
        cout << "\n=== МЕНЮ ===\n"
            << "1. Показати всі книги\n"
            << "2. Додати книгу\n"
            << "3. Видалити книгу\n"
            << "4. Сортувати за роком\n"
            << "5. Сортувати за сторінками\n"
            << "6. Показати книги певного автора\n"
            << "0. Вихід\n"
            << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1: printAll(books, count); break;
        case 2: addBook(books, count); break;
        case 3: removeBook(books, count); break;
        case 4: sortByYear(books, count); break;
        case 5: sortByPages(books, count); break;
        case 6: showByAuthor(books, count); break;
        case 0: cout << "Вихід...\n"; break;
        default: cout << "Невірний вибір!\n";
        }
    } while (choice != 0);

    delete[] books;
    return 0;
}
