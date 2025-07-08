#pragma once
#include "book.h"
#include <vector>
using namespace std;

class BookStore {
    vector<Book*> store;

public:
    ~BookStore();
    void addBook(Book* book);
    void removeOutdatedBooks(int currentYear, int maxAge);
    bool buyBook(string isbn, int quantity,
        string email, string address);
};