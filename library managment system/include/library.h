#pragma once
#include"container.h"
#include <string>


struct Book {
    std::string title;
    std::string author;
    std::string isbn;
    std::string genre;
    bool borrowed;
    bool operator<(const Book& other) const;
    bool operator==(const Book& other) const;
};

class library {
private:
    int available_counter;
    int borrowed_counter;
    int total_books;

public:
    LinkedList<Book> catalog;

    library();
    void insertbook(const Book& book);
    void removebook(const std::string& title);
    void borrowbook(const std::string title);
    void borrowedbooks();
    void searchbytitle(const std::string& title);
    void searchbyauthor(const std::string& author);
    void searchbyisbn(const std::string& isbn);
    void searchbygenre(const std::string& genre);
    void print();
    void printCatalog();
    void statistics();
    void sortCatalog();
    ~library();
};
