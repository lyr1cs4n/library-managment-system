#include "library.h"
#include "container.cpp"
#include <iostream>
#include <algorithm>
using namespace std;
bool Book:: operator<(const Book& other) const
{
    return title < other.title;
}
bool Book::operator==(const Book& other) const
{
    return title == other.title;
}
library:: library()
{
    available_counter = 0;
    borrowed_counter = 0;
    total_books = 0;
}
void library:: insertbook(const Book& book)
{
    catalog.push_back(book);
    total_books++;
    available_counter++;
}
void library:: removebook(const std::string& title)
{
    if(total_books == 0)
    {
        cout<<"Library Is Empty"<<endl;
        return;
    }
    catalog.removeValue(Book{title,"","",""});
    total_books--;
    available_counter--;
}
void library:: borrowbook(const string title)
{
    if(total_books == 0)
    {
        cout<<"Library Is Empty"<<endl;
        return;
    }
    Book* book = catalog.find(Book{title, "", "", ""});
    book->borrowed = true;
    available_counter--;
    borrowed_counter++;
    cout<<"book borrowed"<<endl<<endl;
}
void library:: borrowedbooks()
{
    bool check = false;
    cout<<"Borrowed Books: "<<endl<<endl;
    for (auto it : catalog)
    {
        if (it.borrowed == true)
        {
            cout << "Title: " << it.title << " | Author: " << it.author << " | ISBN: " << it.isbn << " | Genre: " << it.genre << endl <<endl;
            check = true;
        }
    }
    if(!check)
    {
        cout<<"NULL"<<endl;
    }
    cout<<endl;
    statistics();
}
void library:: searchbytitle(const std::string& title)
{
    if(total_books == 0)
    {
        cout<<"Library Is Empty"<<endl;
        return;
    }
    Book* book = catalog.find(Book{title, "", "", ""});
    if (book != nullptr)
    {
        cout << "Book found:" << endl;
        cout << "Title: " << book->title << " | Author: " << book->author << " | ISBN: " << book->isbn << " | Genre: " << book->genre << endl <<endl;
    }
    else
    {
        cout << "Book not found" << endl <<endl;
    }
}
void library:: searchbyauthor(const std::string& author)
{

    if(total_books == 0)
    {
        cout<<"Library Is Empty"<<endl;
        return;
    }
    cout << "Books by author: " << endl;
    for (auto it : catalog)
    {
        if (it.author == author)
        {
            cout << "Title: " << it.title << " | Author: " << it.author << " | ISBN: " << it.isbn << " | Genre: " << it.genre << endl <<endl;
        }
    }
}
void library:: searchbyisbn(const std::string& isbn)
{

    if(total_books == 0)
    {
        cout<<"Library Is Empty"<<endl;
        return;
    }
    cout << "Books by ISBN: " << endl;
    for (auto it : catalog)
    {
        if (it.isbn == isbn)
        {
            cout << "Title: " << it.title << " | Author: " << it.author << " | ISBN: " << it.isbn << " | Genre: " << it.genre << endl <<endl;
        }
    }
}
void library:: searchbygenre(const std::string& genre)
{

    if(total_books == 0)
    {
        cout<<"Library Is Empty"<<endl;
        return;
    }
    cout << "Books by genre: " << endl;
    for (auto it : catalog)
    {
        if (it.genre == genre)
        {
            cout << "Title: " << it.title << " | Author: " << it.author << " | ISBN: " << it.isbn << " | Genre: " << it.genre << endl <<endl;
        }
    }
}
void library:: print()
{
    for (auto it : catalog)
    {
        cout << "Title: " << it.title << " | Author: " << it.author << " | ISBN: " << it.isbn << " | Genre: " << it.genre << endl <<endl;
    }
}
void library:: printCatalog()
{
    bool check = false;
    cout << "Library Catalog:" << endl<< endl;
    if(total_books == 0)
    {
        cout<<"Library Is Empty"<<endl;
        return;
    }
    for (auto& book : catalog)
    {
        cout << "Title: " << book.title << " | Author: " << book.author
             << " | ISBN: " << book.isbn << " | Genre: " << book.genre << endl <<endl;
             check = true;
    }
    statistics();
}
void library:: statistics()
{
    cout << "Total books: " << total_books << endl;
    cout << "Total borrowed books: " << borrowed_counter << endl;
    cout << "Total available books: " << available_counter << endl <<endl;
}
void library:: sortCatalog()
{
    if(total_books == 0)
    {
        cout<<"Library Is Empty"<<endl;
        return;
    }
    catalog.sortElements();
    cout<<"Books Sorted by title in acsendant order"<<endl<<endl;
    printCatalog();
}
library::~library()
{
    //dtor
}
