#ifndef BOOK_H
#define BOOK_H

#include "Including.h"

class Book{
private:
    string name;
    string author;
    string editorial;
    string category;
    string secCategory;
    double isbn;
    int availableCopies;
    double price;
    int sold;

    //

    Book* next = NULL;
    Book* prev = NULL;

public:
    Book(){}
    Book(   string name,
            string author ,
            string editorial,
            string category,
            string secCategory,
            double isbn,
            int availableCopies,
            double price,
            int sold
            ){
        this->name = name;
        this->author = author;
        this->editorial = editorial;
        this->category = category;
        this->secCategory = secCategory;
        this->isbn = isbn;
        this->availableCopies = availableCopies;
        this->price = price;
        this->sold = sold;
    }
    bool NewSell(){
        this->sold++;
        this->availableCopies--;

        return true;
    }
    //
    string getName() const;
    void setName(const string &value);
    string getAuthor() const;
    void setAuthor(const string &value);
    string getEditorial() const;
    void setEditorial(const string &value);
    string getCategory() const;
    void setCategory(const string &value);
    string getSecCategory() const;
    void setSecCategory(const string &value);
    double getIsbn() const;
    void setIsbn(double value);
    int getAvailableCopies() const;
    void setAvailableCopies(int value);
    double getPrice() const;
    void setPrice(double value);
    int getSold() const;
    void setSold(int value);
    Book *getNext() const;
    void setNext(Book *value);
    Book *getPrev() const;
    void setPrev(Book *value);
};

#endif // BOOK_H

string Book::getAuthor() const
{
    return author;
}

void Book::setAuthor(const string &value)
{
    author = value;
}

string Book::getEditorial() const
{
    return editorial;
}

void Book::setEditorial(const string &value)
{
    editorial = value;
}

string Book::getCategory() const
{
    return category;
}

void Book::setCategory(const string &value)
{
    category = value;
}

string Book::getSecCategory() const
{
    return secCategory;
}

void Book::setSecCategory(const string &value)
{
    secCategory = value;
}

double Book::getIsbn() const
{
    return isbn;
}

void Book::setIsbn(double value)
{
    isbn = value;
}

int Book::getAvailableCopies() const
{
    return availableCopies;
}

void Book::setAvailableCopies(int value)
{
    availableCopies = value;
}

double Book::getPrice() const
{
    return price;
}

void Book::setPrice(double value)
{
    price = value;
}

int Book::getSold() const
{
    return sold;
}

void Book::setSold(int value)
{
    sold = value;
}

Book *Book::getNext() const
{
    return next;
}

void Book::setNext(Book *value)
{
    next = value;
}

Book *Book::getPrev() const
{
    return prev;
}

void Book::setPrev(Book *value)
{
    prev = value;
}

string Book::getName() const
{
    return name;
}

void Book::setName(const string &value)
{
    name = value;
}
