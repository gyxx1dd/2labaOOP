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

    // ��������� ����� � ����������
    library.addBook(Book("Maksim", "blablabla", "vydavnictvo12", 2020, 300));
    library.addBook(Book("Anton", "kykykyky", "vydavnictvo21424214", 2019, 250));
    library.addBook(Book("Vlad", "����� � ���", "vydavnictvo0000", 2021, 350));

    // ������ � ������������ ������� ������
    cout << "������ ������� ������: ";
    string userInput;
    cin >> userInput;

    // ����� ���� �� ��������� ������
    vector<Book> foundBooks = library.findBooksByAuthor(userInput);

    if (foundBooks.empty()) {
        cout << "����� ������ ��������." << endl;
    }
    else {
        cout << "������ �����:" << endl;
        for (const Book& book : foundBooks) {
            cout << "�����: " << book.getAuthor() << ", �����: " << book.getTitle() <<'\t'<<", �����������:"<<'\t' << book.getPublisher() << endl;
        }
    }

    return 0;
}
