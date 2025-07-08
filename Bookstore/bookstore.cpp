#include "bookstore.h"
#include <iostream>
#include <algorithm>
using namespace std;

BookStore::~BookStore() {
    for (Book* book : store) {
        delete book;
    }
}

void BookStore::addBook(Book* book) {
    store.push_back(book);
}

void BookStore::removeOutdatedBooks(int currentYear, int maxAge) {
    for (int i = 0; i < store.size(); i++) {
        if (currentYear - store[i]->getYear() > maxAge) {
            cout << "Removed outdated book " << store[i]->getTitle() << endl;
            delete store[i];
            store.erase(store.begin() + i);
            i--; 
        }
    }
}

bool BookStore::buyBook(string isbn, int quantity,
    string email, string address) {
    for (int i = 0; i < store.size(); i++) {
        if (store[i]->getISBN() == isbn) {
            return store[i]->purchase(quantity, email, address);
        }
    }

    cout << "Error: Book not found" << endl;
    return false;
}