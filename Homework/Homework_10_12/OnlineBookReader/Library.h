#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED
#include "Book.h"
#include <vector>
#include <iostream>

// A class representing all the books in the library
class Library{

// Creating a stack of initial books
Library(){InitiateCollection();}

public:
void AddBook(Book book)
{
   m_bookCollection.push_back(book);
}


void BookSort(); // Sorting the books in alphabetical order.

std::vector<Book> m_bookCollection;
private:
// bool utility function to enable sorting
// Alphabetical ordering, first by author and then by book title.
 static bool compare(const Book& book1, const Book& book2);

 void InitiateCollection();


};

#endif // LIBRARY_H_INCLUDED
