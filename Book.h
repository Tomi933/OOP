#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int year;
    int pages;

public:
   
    Book();


    Book(string t, string a, int y, int p);

 
    Book(const Book& other);


    void setTitle(string t);
    void setAuthor(string a);
    void setYear(int y);
    void setPages(int p);

    string getTitle() const;
    string getAuthor() const;
    int getYear() const;
    int getPages() const;


    void print() const;
};

