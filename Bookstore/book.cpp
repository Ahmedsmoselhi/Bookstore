#include "book.h"
#include <iostream>
using namespace std;

bool Book::isOutdated(int currentYear, int maxAge) {
    return (currentYear - year) > maxAge;
}

bool PaperBook::hasEnoughStock(int requested) {
    return quantity >= requested;
}

bool PaperBook::purchase(int qty, string email, string address) {
    if (qty <= 0) {
        cout << "Invalid quantity" << endl;
        return false;
    }

    if (!hasEnoughStock(qty)) {
        cout << "Only " << quantity << " left in stock" << endl;
        return false;
    }

    double totalPrice = qty * price;
    cout << "Purchased successfully" << endl;
    cout << "Total Price = " << totalPrice << endl;

    quantity -= qty;
    cout << "Shipping paper book to: " << address << endl;

    return true;
}

bool EBook::purchase(int qty, string email, string address) {
    if (qty <= 0) {
        cout << "Invalid quantity" << endl;
        return false;
    }

    double totalPrice = qty * price;
    cout << "Purchased successfully" << endl;
    cout << "Total Price = " << totalPrice << endl;

    cout << "Sending ebook to: " << email << endl;
    cout << "File type: " << fileType << endl;

    return true;
}

bool ShowcaseBook::purchase(int qty, string email, string address) {
    cout << "Book is showcase only" << endl;
    return false;
}