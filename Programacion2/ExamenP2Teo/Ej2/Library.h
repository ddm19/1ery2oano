// Programación 2 - Examen Junio 2020         

#ifndef __LIBRARY__
#define __LIBRARY__

#include <string>
#include <vector>

#include "Author.h"
#include "Book.h"
#include "Reader.h"

using namespace std;

// Excepciones que puede lanzar la clase
enum ExceptionsLibrary {
    unknown_author,
    author_exists,
    unknown_book,
    book_exists,
    unknown_reader,
    reader_exists
};

class Library {
  private:
    static unsigned int nextReaderId;
    string name;
    vector<Author> authors;
    vector<Book> books;
    vector<Reader> readers;
    int searchAuthor(string authorName) const;
    int searchBook(string bookTitle) const;
    int searchReader(unsigned int readerId) const;

  public:
    Library(string name);
    void createAuthor(string authorName);
    void createBook(string authorName, string bookTitle, unsigned int pages,
                    bool prized);
    unsigned int createReader(string readerName);
    void lendBook(string bookTitle, unsigned int readerId);
    void returnBook(string bookTitle, unsigned int readerId);
    string report () const;
    
};

#endif
