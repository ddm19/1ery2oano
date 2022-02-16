// Programación 2 - Examen Junio 2020         

#ifndef __AUTHOR__
#define __AUTHOR__

#include <string>
#include <vector>

#include "Book.h"

using namespace std;

class Author {
    private:
        string name;
        vector<string> books;
    public:
        Author(string name);
        string getName() const;
        void addBook(string bookTitle);
        vector<string> getBooks(void) const;
};

#endif
