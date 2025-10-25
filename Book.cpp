#include "Book.h"
#include <iostream>
using namespace std;


Book::Book() : title(""), author(""), year(0), pages(0) {}


Book::Book(string t, string a, int y, int p)
    : title(t), author(a), year(y), pages(p) {
}


Book::Book(const Book& other)
    : title(other.title), author(other.author),
    year(other.year), pages(other.pages) {
}


void Book::setTitle(string t) { title = t; }
void Book::setAuthor(string a) { author = a; }
void Book::setYear(int y) { year = y; }
void Book::setPages(int p) { pages = p; }


string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
int Book::getPages() const { return pages; }


void Book::print() const {
    cout << "Назва: " << title
        << ", Автор: " << author
        << ", Рік: " << year
        << ", Сторінок: " << pages << endl;
}

