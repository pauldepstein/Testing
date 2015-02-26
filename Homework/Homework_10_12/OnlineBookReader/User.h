#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <string>
#include <stdexcept>
#include <iostream>
#include <"Book.h">
#include <"Library">

// A class for representing a user
// User has a maximum of one book, represented by a string.
// Each book has a return date represented as a double which can
// be extended.
// Users are represented by strings.

class User{

public:
User(std::string username):m_username(username)
{
   numBooks = 0;
}

// Representing the reading of a book
void ReadBook(Book& book, double date )
{
    if book.hasUser
    {
        std::cout << "Book already has a user -- request declined.";
        return;
    }

    if(numBooks >=1)
    {
        std::cout << "User already has a book -- request declined."
        return;
    }

    m_book = book;
    m_book.hasUser = true;
    numBooks++;
    m_date = date;
}

void TurnPage()
{
    m_book.TurnPage();
}

double getDate()
{
    return m_date;
}

void setDate(double date)
{
    m_date = date;
}

void setNumBooks(numBooks)
{
    m_numBooks = numBooks;
}

void returnCurrentBook()
{
    m_numBooks--;
}

// Search library for desired book -- return true if found.
bool findBook(const Book& book)
{
    Library library;

    library.BookSort();

    for(int i = 0; i < library.m_bookCollection.size(); i++)
        if(library.m_bookCollection[i] == book)
            return true;

    return false;

}

// Extending the loan as requested
// date denotes the amount of extra time for the loan.
void getExtension(double date)
{
    if(date <= 0)
        throw std::domain_error("Extension should be for a positive time");

    m_date += date;
}

void display()
{
    std::cout << "Displaying user info for " << m_username << std::endl;
    m_book.display();
    std::cout << std::endl;
    std::cout << "Book is due on " << m_date << std::endl;
}

private:
std::string m_username;
Book m_book;
int m_numBooks;
double m_date;

};

#endif // USER_H_INCLUDED
