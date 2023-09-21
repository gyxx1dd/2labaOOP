#include <iostream>
#include <string>
#include <vector>

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
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    vector<Book> findBooksByAuthor(const string& author) {
        vector<Book> result;
        for (const Book& book : books) {
            if (book.getAuthor() == author) {
                result.push_back(book);
            }
        }
        return result;
    }
};

int main() 
{
    setlocale(LC_ALL, "Ukrainian");
    Library library;

    // Добавляем книги в библиотеку
    library.addBook(Book("Maksim", "blablabla", "vydavnictvo12", 2020, 300));
    library.addBook(Book("Anton", "kykykyky", "vydavnictvo21424214", 2019, 250));
    library.addBook(Book("Vlad", "Война и мир", "vydavnictvo0000", 2021, 350));

    // Запрос у пользователя фамилии автора
    cout << "Введіть прізвище автора: ";
    string userInput;
    cin >> userInput;

    // Поиск книг по заданному автору
    vector<Book> foundBooks = library.findBooksByAuthor(userInput);

    if (foundBooks.empty()) {
        cout << "Книги автора ненайдені." << endl;
    }
    else {
        cout << "Найдені книги:" << endl;
        for (const Book& book : foundBooks) {
            cout << "Автор: " << book.getAuthor() << ", Назва: " << book.getTitle() <<'\t'<<", Видавництво:"<<'\t' << book.getPublisher() << endl;
        }
    }

    return 0;
}
