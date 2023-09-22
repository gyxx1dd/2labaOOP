#include <iostream>
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