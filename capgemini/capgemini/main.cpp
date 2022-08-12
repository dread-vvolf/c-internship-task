#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <sstream>

class book {
protected:
    std::string
        bookName,
        authorName,
        bookGenre,
        publisher;
    int
        yearOfIssue,
        pageNr;

public:
    std::string getBookName();
    std::string getAuthorName();
    std::string getBookGenre();
    int getYearOfIssue();
    std::string getPublisher();
    int getPageNr();
    void setAll(
        std::string bookName,
        std::string authorName,
        std::string bookGenre,
        int yearOfIssue,
        std::string publisher,
        int pageNr);
    void deleteBook(std::string bookName);

    //reports

};
std::string book::getBookName() {
    return this->bookName;
}
std::string book::getAuthorName() {
    return this->authorName;
}
std::string book::getBookGenre() {
    return this->bookGenre;
}
int book::getYearOfIssue() {
    return this->yearOfIssue;
}
std::string book::getPublisher() {
    return this->publisher;
}
int book::getPageNr() {
    return this->pageNr;
}

void book::setAll(
    std::string bookName,
    std::string authorName,
    std::string bookGenre,
    int yearOfIssue,
    std::string publisher,
    int pageNr) {
        this->bookName = bookName;
        this->authorName = authorName;
        this->bookGenre = bookGenre;
        this->yearOfIssue = yearOfIssue;
        this->publisher = publisher;
        this->pageNr = pageNr;
}






class books : public book {
protected:
    book* data;
    int size;
    std::fstream database;
    std::string 
        bookName,
        authorName,
        bookGenre,
        publisher,
        temp1,
        temp2;
    int
        yearOfIssue,
        pageNr;
public:
    books();
    void del();
    int getSize();
    void setSize(int size);
    void addBook(
        std::string bookName,
        std::string authorName,
        std::string bookGenre,
        int yearOfIssue,
        std::string publisher,
        int pageNr
    );
    void deleteBook(std::string bookName);
    void showAuthorBooks(std::string authorName);
    void showByGenrePublisher(std::string bookGenre, std::string publisher);
    void showPublisherMaxBooks();
    void save(
        int i,
        std::string bookName,
        std::string authorName,
        std::string bookGenre,
        int yearOfIssue,
        std::string publisher,
        int pageNr
    );
    void createFile();
    void saveToFile();
    void loadFromFile();
    int convertToInt(std::string conv);

};
int books::getSize() {
    this->size = 0;
    int lines = 0;
    database.open("books.txt");
    while (getline(database, temp1)) {
        if (temp1 == "") break;
        else lines++;
    }
    database.close();
    size = lines / 6;
    return size;
}
books::books() {
    getSize();
    data = new book[size];
}
int books::convertToInt(std::string conv) {
    int a;
    std::stringstream s(conv);
    s >> a;
    return a;
}
void books::save(
    int i,
    std::string bookName,
    std::string authorName,
    std::string bookGenre,
    int yearOfIssue,
    std::string publisher,
    int pageNr) {
    data[i].setAll(bookName, authorName, bookGenre, yearOfIssue, publisher, pageNr);
}

void books::createFile() {
    bool good();
    std::fstream database("books.txt");
    do {
        if (database.good()) break;
        else std::ofstream database("books.txt");
    } while (!database.good());
    database.close();
}
void books::saveToFile() {
    std::ofstream("books.txt");
    database.open("books.txt");
    for (int i = 0; i < size; i++) {
        database
            << data[i].getBookName() << "\n"
            << data[i].getAuthorName() << "\n"
            << data[i].getBookGenre() << "\n"
            << data[i].getYearOfIssue() << "\n"
            << data[i].getPublisher() << "\n"
            << data[i].getPageNr() << "\n";
    }

}
void books::loadFromFile() {
    database.open("books.txt");
    for (int i = 0; i < size; i++) {
       std::getline(database, bookName); 
       std::getline(database, authorName);
       std::getline(database, bookGenre);
       std::getline(database, temp1);
       yearOfIssue = convertToInt(temp1);
       std::getline(database, publisher);
       std::getline(database, temp2);
       pageNr = convertToInt(temp2);
       save(i, bookName, authorName, bookGenre, yearOfIssue, publisher, pageNr);
    }
    database.close();
}
void books::setSize(int size) {
    this->size = size;
}
void books::del() {
    delete[] data;
}
void books::addBook(
    std::string bookName,
    std::string authorName,
    std::string bookGenre,
    int yearOfIssue,
    std::string publisher,
    int pageNr) {
    del();
    size += 1;
    data = new book[size];
    loadFromFile();
    data[this->size].setAll(bookName, authorName, bookGenre, yearOfIssue, publisher, pageNr);
}

void books::deleteBook(std::string bookName) {
    for (int i = 0; i < size; i++) {
        if (bookName == data[i].getBookName()) {
            std::cout << data[i].getBookName() << std::endl; //add deletion
        }
    }
}
void books::showAuthorBooks(std::string authorName) {
    for (int i = 0; i < size; i++) {
        if (authorName == data[i].getAuthorName()) {
            std::cout << data[i].getBookName() << std::endl;
        }
    }
}
void books::showByGenrePublisher(std::string bookGenre, std::string publisher) {
    for (int i = 0; i < size; i++) {
        if (bookGenre == data[i].getBookGenre()) {
            if (publisher == data[i].getPublisher()) {
                std::cout << data[i].getBookName() << std::endl;
            }
        }
    }
}
void books::showPublisherMaxBooks() {
    int curr = 0;
    for (int i = 0; i < size; i++) {
        
    }
}





void menu() {
    std::cout <<
        "1. Add book." << std::endl <<
        "2. Delete book." << std::endl <<
        "3. Show all books by the same author." << std::endl <<
        "4. Show all books of a given genre and publisher." << std::endl <<
        "5. Show the name of the publisher with the maximum quantity of the books." << std::endl <<
        "6. Show TOP-3 genres." << std::endl <<
        "7. Save list of books to file." << std::endl <<
        "8. Load list of books from file." << std::endl;
}

int main() {
    bool end = 0;
    std::string bookName, authorName, bookGenre, publisher;
    int booksNr = 0, yearOfIssue, pageNr;
    books b;
    b.loadFromFile();
    while (!end) {
        _getch();
        system("cls");
        menu();
        int getChar = _getch();
        switch (getChar) {
        case '1': {
            std::cin >> bookName;
            std::cin >> authorName;
            std::cin >> bookGenre;
            std::cin >> yearOfIssue;
            std::cin >> publisher;
            std::cin >> pageNr;
            new book();
            b.addBook(bookName, authorName, bookGenre, yearOfIssue, publisher, pageNr);
            booksNr++;
            b.setSize(booksNr);
            break;
        }
        case '2': {
            std::cin >> bookName;
            b.deleteBook(bookName);
            break;
        }
        case '3': {
            std::cin >> authorName;
            b.showAuthorBooks(authorName);
            break;
        }
        case '4': {
            std::cin >> bookGenre;
            std::cin >> publisher;
            b.showByGenrePublisher(bookGenre, publisher);
            break;
        }
        case '5': {
            std::cin >> publisher;
            break;
        }
        case '6': {
            break;
        }
        case '7': {
            b.saveToFile();
            break;
        }
        case '8': {
            b.loadFromFile();
            break;
        }
        }
    }
}
