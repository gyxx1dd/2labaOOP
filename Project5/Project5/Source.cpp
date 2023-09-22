#include <iostream>
#include <string>
#include "Library.h"

using namespace std;


int main() {
    setlocale(LC_ALL, "Ukrainian");
    Library library;

    library.addBook(Book("Maksim", "blablabla", "vydavnictvo12", 2020, 300));
    library.addBook(Book("Anton", "kykykyky", "vydavnictvo21424214", 2019, 250));
    library.addBook(Book("Vlad", "vojna i mir", "vydavnictvo0000", 2021, 350));

    cout << "Input surname: ";
    string userInput;
    cin >> userInput;

    library.findBooksByAuthor(userInput);

    return 0;
}
