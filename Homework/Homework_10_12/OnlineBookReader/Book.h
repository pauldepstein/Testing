#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
#include <string>
#include <iostream>
// A class representing a book
// Each book has a title and an author and a number of pages

class Book{

public:
Book(std::string Title, std::string Author):m_title(Title), m_author(Author),m_currentPage(0)
{
    hasUser = false;
}

bool hasUser; // publically accessible variable indicating if book has a user
std::string getAuthor()const{return m_author;}
std::string getTitle()const {return m_title;}
void setPageNum(unsigned count){m_pageNum = count;}
unsigned getPageNum(){return m_pageNum; }
bool operator ==(Book& rhs)
{
    return m_title == rhs.m_title && m_author == rhs.m_author;
}

void turnPage()
{
    if(m_currentPage < m_pageNum-1)
        m_currentPage++;

    else
        std::cout << "At end of book -- can't turn page";
}

void display()
{
    std::cout << std::endl;
    std::cout << "Displaying details of book " << std::endl;
    std::cout << "Author is " << m_author << std::endl;
    std::cout << "Title is " << m_title << std::endl;
    std::cout << "Current page is " << m_currentPage << std::endl;
}

private:
std::string m_author;
std::string m_title;
unsigned m_pageNum;
unsigned m_currentPage; // The current page.
};

#endif // BOOK_H_INCLUDED
