#pragma once
#include <string>
using namespace std;

class Book {
protected:
    string isbn;
    string title;
    string author;
    int year;
    double price;

public:
    Book(string isbn, string title,
        string author, int year, double price)
        : isbn(isbn), title(title), author(author),
        year(year), price(price) {}

    virtual ~Book() {}

    virtual bool purchase(int quantity, string email,
        string address) = 0;
    virtual bool isOutdated(int currentYear, int maxAge);

    string getISBN() { return isbn; }
    string getTitle() { return title; }
    int getYear() { return year; }
    double getPrice() { return price; }
};

class PaperBook : public Book {
    int quantity;

public:
    PaperBook(string isbn, string title,
        string author, int year, double price, int quantity)
        : Book(isbn, title, author, year, price), quantity(quantity) {}

    bool purchase(int quantity, string email, string address);
    bool hasEnoughStock(int requested);
};

class EBook : public Book {
    string fileType;

public:
    EBook(string isbn, string title,
        string author, int year, double price,
        string fileType)
        : Book(isbn, title, author, year, price), fileType(fileType) {}

    bool purchase(int quantity, string email, string address);
};

class ShowcaseBook : public Book {
public:
    ShowcaseBook(string isbn, string title,
        string author, int year, double price)
        : Book(isbn, title, author, year, price) {}

    bool purchase(int quantity, string email, string address);
};