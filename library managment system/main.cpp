#include <iostream>
#include "container.h"
#include "library.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>
#include <iomanip>
#include <iostream>
#include <windows.h>
using namespace std;


void clear()
{

    cout<<endl;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    cout  <<"saving";
    for (int i = 2; i > 0; i--)
    {
        cout<<".";
        sleep(1);
    }
    system("CLS");

}


void check()
{

    int ch;
    cout<<endl;
    cout<<"\033[33mPress Esc to return back to the main screen. \033[0m";
    do
    {
        ch=getch();
        if (ch==27)
        {
            system("CLS");
            sleep(1);
        }
    }
    while (ch!=27);

}


void myFunction(string x)
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << setw(50) << setfill('*') << "" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    cout << setw(32) << setfill(' ') << x << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << setw(50) << setfill('*') << "" << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

}

void StartScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "*****************************************************" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "*                                                   *" << endl;
    cout << "*";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    cout<<  "              LIBRARY MANAGEMENT SYSTEM            ";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout<< "*" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "*                                                   *" << endl;
    cout << "*****************************************************" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout<<"\033[33m| 1 |\033[0m"<<" Book Catalog" << endl;
    cout<<"\033[33m| 2 |\033[0m"<<" Book insertion" << endl;
    cout<<"\033[33m| 3 |\033[0m"<<" Book Removal" << endl;
    cout<<"\033[33m| 4 |\033[0m"<<" Book Search" << endl;
    cout<<"\033[33m| 5 |\033[0m"<<" Book Borrowing" << endl;
    cout<<"\033[33m| 6 |\033[0m"<<" Book Sorting" << endl;
    cout<<"\033[33m| 7 |\033[0m"<<" Book Statistics" << endl;
    cout<<"\033[33m| 0 |\033[0m"<<" Exit" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "==========================================" << endl;
    cout << "Type your option : ";
}
void search_menu(library * lib)
{
    int key;
    system("CLS");
    myFunction("Book Search");
    cout << "\033[33m| 1 |\033[0m"
         << " Search By title" << endl;
    cout << "\033[33m| 2 |\033[0m"
         << " Search By Author" << endl;
    cout << "\033[33m| 3 |\033[0m"
         << " Search By ISBN" << endl;
    cout << "\033[33m| 4 |\033[0m"
         << " Search By Genre" << endl;
    cout << "\033[33m| 0 |\033[0m"
         << " Return Main" << endl <<endl;
    cout << "[*] "
         << "\033[33mChoose The Method You Want To Search With: \033[0m";
    cin >> key;
    cout << "\n\n";

    if (key == 1)
    {
        system("CLS");
        myFunction("Search By Title");
        string title;
        cout<<"Enter The Title : ";
        cin>>title;
        lib->searchbytitle(title);
        check();
    }

    else if (key == 2)
    {
        system("CLS");
        myFunction("Search By Author");
        string Author;
        cout<<"Enter The Author : ";
        cin>>Author;
        lib->searchbyauthor(Author);
        check();
    }

    else if (key == 3)
    {
        system("CLS");
        myFunction("Search By ISBN");
        string ISBN;
        cout<<"Enter The ISBN : ";
        cin>>ISBN;
        lib->searchbyisbn(ISBN);
        check();
    }
    else if (key == 4)
    {
        system("CLS");
        myFunction("Search By Genre");
        string Genre;
        cout<<"Enter The Genre : ";
        cin>>Genre;
        lib->searchbygenre(Genre);
        check();
    }
    else
    {
        system("CLS");
    }

}
void Borrowed_menu(library * lib)
{
    int key;
    system("CLS");
    myFunction("Book Search");
    cout << "\033[33m| 1 |\033[0m"
         << " Borrow Books" << endl;
    cout << "\033[33m| 2 |\033[0m"
         << " Show Borrowed Books" << endl;
    cout << "\033[33m| 0 |\033[0m"
         << " Return Main" << endl <<endl;
    cout << "[*] "
         << "\033[33mChoose The Method You Want To Search With: \033[0m";
    cin >> key;
    cout << "\n\n";

    if (key == 1)
    {
        system("CLS");
        myFunction("Borrow Books");
        string title;
        cout<<"Enter the title of the book you want to borrow: ";
        cin>>title;
        lib->borrowbook(title);
        clear();
    }

    else if (key == 2)
    {
        system("CLS");
        myFunction("Borrowed Books");
        lib->borrowedbooks();
        check();
    }
    else
    {
        system("CLS");
    }

}

int main()
{

    int d;
    library lib;
    while(true)
    {
        StartScreen();
        cin>> d;
        cout<<"\n\n\n";

        if (d==0)
        {
            cout<<"\033[33mThanks for using my project :) \033[0m"<<endl;
            break;
        }


        if (d==1)
        {

            system("CLS");
            myFunction("Book Catalog");
            lib.printCatalog();
            check();
        }


        if (d==2)
        {
            string title;
            string author;
            string isbn;
            string genre;
            system("CLS");
            myFunction("Book insertion");
            cout<<"Enter Book Title : ";
            cin>>title;
            cout<<"Enter Book Author : ";
            cin>>author;
            cout<<"Enter Book ISBN : ";
            cin>>isbn;
            cout<<"Enter Book Genre : ";
            cin>>genre;
            Book book = Book{title,author,isbn,genre};
            lib.insertbook(book);
            clear();
        }


        if (d==3)
        {
            system("CLS");
            myFunction("Book Removal");
            string title;
            cout<<"Enter Book Title : ";
            cin>>title;
            lib.removebook(title);
            clear();
        }


        if (d==4)
        {
            system("CLS");
            myFunction("Book Search");
            search_menu(&lib);
            system("CLS");
        }


        if (d==5)
        {
            system("CLS");
            myFunction("Book Borrowing");
            Borrowed_menu(&lib);
            system("CLS");
        }


        if (d==6)
        {
            system("CLS");
            myFunction("Book Sorting");
            lib.sortCatalog();
            check();
        }


        if (d==7)
        {
            system("CLS");
            myFunction("Book Statistics");
            lib.statistics();
            check();
        }

    }

    return 0;
}
