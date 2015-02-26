#include "Library.h"
#include <algorithm>

void Library::InitiateCollection()
{
    Book book1 = Book("This title", "John Smith");
    Book book2 = Book("This Other title", "John Smith");
    Book book3 = Book("Another title", "Mary Smith");

    m_bookCollection.push_back(book1);
    m_bookCollection.push_back(book2);
    m_bookCollection.push_back(book3);
}
void Library::BookSort()
{
    std::sort(m_bookCollection.begin(), m_bookCollection.end(), compare);
}

bool Library::compare(const Book& book1, const Book& book2)
{
    if(book1.getAuthor() < book2.getAuthor())
        return true;

    if(book2.getAuthor()< book1.getAuthor())
        return false;

    return(book1.getTitle() < book2.getTitle());
}


