#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string author;
    string title;
    string publisher;
    int publicationYear;
    int pageCount;

public:
    Book(const string& author, const string& title, const string& publisher,
        int publicationYear, int pageCount)
        : author(author), title(title), publisher(publisher),
        publicationYear(publicationYear), pageCount(pageCount) {}

    string getAuthor() const { return author; }
    string getTitle() const { return title; }
    string getPublisher() const { return publisher; }
    int getPublicationYear() const { return publicationYear; }
    int getPageCount() const { return pageCount; }
};

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
                    cout << "Найдені книги автора '" << author << "':" << endl;
                    found = true;
                }
                cout << "Автор: " << books[i]->getAuthor() << ", Назва: " << books[i]->getTitle() << ", Видавництво: " << books[i]->getPublisher() << endl;
            }
        }
        if (!found) {
            cout << "Книги автора '" << author << "' не найдені." << endl;
        }
    }

    ~Library() {
        for (int i = 0; i < bookCount; i++) {
            delete books[i];
        }
        delete[] books;
    }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");
    Library library;

    library.addBook(Book("Maksim", "blablabla", "vydavnictvo12", 2020, 300));
    library.addBook(Book("Anton", "kykykyky", "vydavnictvo21424214", 2019, 250));
    library.addBook(Book("Vlad", "vojna i mir", "vydavnictvo0000", 2021, 350));

    cout << "Введіть прізвище автора: ";
    string userInput;
    cin >> userInput;

    library.findBooksByAuthor(userInput);

    return 0;
}
