#include <iostream>
#include "Book.h"
using namespace std;


class Library {
private:
    Book** books;
    int bookCount;

public:
    Library() : books(nullptr), bookCount(0) {}

    void addBook(const Book& book) {
        Book** newBooks = new Book * [bookCount + 1];
        for (int i = 0; i < bookCount; i++) {
            newBooks[i] = books[i];
        }
        newBooks[bookCount] = new Book(book);
        delete[] books;
        books = newBooks;
        bookCount++;
    }

    void findBooksByAuthor(const string& author) {
        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (books[i]->getAuthor() == author) {
                if (!found) {
                    cout << "Author's books found '" << author << "':" << endl;
                    found = true;
                }
                cout << "Author: " << books[i]->getAuthor() << ", Name: " << books[i]->getTitle() << ", publishing house: " << books[i]->getPublisher() << endl;
            }
        }
        if (!found) {
            cout << "author's books '" << author << "' not found." << endl;
        }
    }

    ~Library() {
        for (int i = 0; i < bookCount; i++) {
            delete books[i];
        }
        delete[] books;
    }
};