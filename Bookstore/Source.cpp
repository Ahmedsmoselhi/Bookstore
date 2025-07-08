#include "bookstore.h"
#include <iostream>
using namespace std;

int main() {
    BookStore egyptStore;

    // Add books
    egyptStore.addBook(new PaperBook("a001", "Book A", "Ahmed", 2020, 100, 5));
    egyptStore.addBook(new EBook("b002", "Book B", "Mona", 2022, 80, "PDF"));
    egyptStore.addBook(new ShowcaseBook("c003", "Book C", "Omar", 1990, 500));
    egyptStore.addBook(new PaperBook("d004", "Book D", "Fatma", 1995, 120, 2));

    cout << "===== TEST 1: Buy paper book to Cairo =====" << endl;
    egyptStore.buyBook("a001", 2, "", " Cairo");
    cout << endl;

    cout << "===== TEST 2: Buy ebook  =====" << endl;
    egyptStore.buyBook("b002", 1, "ahmedsmoselhi@gmail.com", "");
    cout << endl;

    cout << "===== TEST 3: Try to buy showcase book =====" << endl;
    egyptStore.buyBook("c003", 1, "", "");
    cout << endl;

    cout << "===== TEST 4: Remove old books (2023, max 25 years) =====" << endl;
    egyptStore.removeOutdatedBooks(2023, 25);
    cout << endl;

    cout << "===== TEST 5: Buy after removal =====" << endl;
    egyptStore.buyBook("d004", 1, "ahmedsmoselhi@gmail.com", "Giza");
    cout << endl;

    return 0;
}