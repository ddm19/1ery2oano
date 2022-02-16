// Programación 2 - Examen Junio 2020         

#ifndef __BOOK__
#define __BOOK__

#include <string>

using namespace std;

class Book {
    private:
        string title;
        unsigned int pages;
        bool prized;
    public:
        Book(string title, unsigned int pages, bool prized);
        string getTitle() const;
        unsigned int getPages() const;
        bool isPrized() const;
};

#endif
