#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include "Book.h"

class Bookstore{

private:
    int bookCont;
    double currentISBN;

    Book* start = NULL;
    Book* end = NULL;

    ///--------------

    Book* registerBook(){

        string name;
        string author;
        string editorial;
        string category;
        string secCategory;
        double isbn;
        int availableCopies;
        double price;
        int sold = 0;

        char responce;

        cout << "Name: ";
        cin >> name;

        cout << "Author: ";
        cin >> author;

        cout << "Editorial: ";
        cin >> editorial;

        cout << "Category: ";
        cin >> category;

        cout << "Second Category: ";
        cin >> secCategory;

        isbn = currentISBN++;

        cout << "Availible Copies: ";
        cin >> availableCopies;

        cout << "Price: ";
        cin >> price;

        cout << "Is this correct? y/n: ";
        cin >> responce;
        if(responce!='y'){
            cout << " \nNo changes where made" << endl;
            return NULL;
        }

        Book* nuevo = new Book(name, author, editorial, category, secCategory, isbn, availableCopies, price, sold);
        return nuevo;
    }
    bool NewBook(Book* book){
        if(book == NULL)
            return false;

        if(this->start == NULL){
            this->start = book;
            this->end = book;
        } else {

            book->setPrev(end);
            this->end->setNext(book);
            this->end = book;

        }
        return true;
    }
    Book* searchBook(string name){
        Book* node = this->start;

        while (node != NULL)
        {
            if (node->getName() == name)
                return node;
            node = node->getNext();
        }
        cout << " NOT FOUND!!" << endl;
        return NULL;
    }
    bool newSell(Book* bookSold){
        if(bookSold == NULL)
            return false;

        bookSold->NewSell();
        if(bookSold->getAvailableCopies() == 0)
        {
            deleteBook(bookSold);
        }
        cout << "Sold" << endl;
        return true;
    }
    bool deleteBook(Book* deleted){
        if (deleted == NULL)
            return false;

        if(deleted == end && deleted == start){
            end = start = NULL;
        }
        else if(deleted == start){
            deleted->getNext()->setPrev(NULL);
            start = deleted->getNext();
        }
        else if(deleted == end){
            deleted->getPrev()->setNext(NULL);
            end = deleted->getPrev();
        }
        else{
            Book* prev = deleted->getPrev();
            Book* next = deleted->getNext();

            prev->setNext(next);
            next->setPrev(prev);

        }
        delete(deleted);
        bookCont--;
        return true;
    }
    void showBook(Book* showed){

        if (showed == NULL)
            return;

        cout.precision(13);
        cout << "---------------------------------------" << endl;
        cout << "Name: " << showed->getName() << endl;
        cout << "Author: " << showed->getAuthor() << endl;
        cout << "Editorial: " << showed->getEditorial() << endl;
        cout << "Category: " << showed->getCategory() << endl;
        cout << "Second Category: " << showed->getSecCategory() << endl;
        cout << "ISBN: " << showed->getIsbn() << endl;
        cout << "Available Copies: " << showed->getAvailableCopies() << endl;
        cout << "Price: " << showed->getPrice() << endl;
        cout << "Sold: " << showed->getSold() << endl;
    }
    friend ostream &operator<<(ofstream &fout, const Book &book){

        fout.precision(13);
        fout << '#';
        fout << "Name: " << book.getName() << '$';
        fout << "Author: " << book.getAuthor() << '$';
        fout << "Editorial: " << book.getEditorial() << '$';
        fout << "Category: " << book.getCategory() << '$';
        fout << "Second Category: " << book.getSecCategory() << '$';
        fout << "ISBN: " << book.getIsbn() << '$';
        fout << "Available Copies: " << book.getAvailableCopies() << '$';
        fout << "Price: " << book.getPrice() << '$';
        fout << "Sold: " << book.getSold() << '$';

        return fout;
    }

public:
    Bookstore(){
        bookCont = 0;
        currentISBN = 1000000000000;

        this->start = NULL;
        this->end = NULL;
    }
    bool showMenu(){

        int choice;

        while(!load())
            cout << "//";

        system("CLS");

        cout<< R"(


               _________ .__        _____        ________      .___
               \_   ___ \|  |__    /  |  |  _____\_____  \   __| _/
               /    \  \/|  |  \  /   |  |_/  ___/ _(__  <  / __ |
               \     \___|   Y  \/    ^   /\___ \ /       \/ /_/ |
                \______  /___|  /\____   |/____  >______  /\____ |
                       \/     \/      |__|     \/       \/      \/


               )" << '\n';
        cout << "\nBookstore system 9000 \n" << endl;
        cout << "1. Add book" << endl;
        cout << "2. Delete book" << endl;
        cout << "3. Search book" << endl;
        cout << "4. Buy book" << endl;
        cout << "5. Show all books" << endl;
        cout << "0. Exit" << endl;

        cin >> choice;

        switch(choice)
        {
        case 0: {
            save();
            return false;
        }break;
        case 1: NewBook(registerBook());
            break;
        case 2: deleteBook(searchBook(nameBook()));
            break;
        case 3: showBook(searchBook(nameBook()));
            break;
        case 4: newSell(searchBook(nameBook()));
            break;
        case 5: showAll();
            break;
        }
        cin.ignore();
        cout << "Press Enter to Continue";
        cin.ignore();

        return true;
    }
    string nameBook(){
        string value;

        cout << "Name to search: ";
        cin >> value;

        return value;
    }
    void showAll(){

        if (start == NULL){
            cout << "No Books" << endl;
            return;
        }

        Book* node = this->start;

        while (node != NULL){
            showBook(node);
            node = node->getNext();
        }
    }
    bool save(){
        if (start == NULL)
            return false;

        ofstream fout;
        Book* node = this->start;

        fout.open("datos.txt", ofstream::trunc | ios::app);

        while (node != NULL){
            fout << node;
            node = node->getNext();
        }
        fout.close();
        return true;
    }
    bool load(){
        ifstream fin;
        fin.open("datos.txt", ios::app);

        char atribute = '$';
        char object = '#';
        Book* nuevo = new Book();



        fin.close();
        return true;
    }
};

#endif // BOOKSTORE_H
