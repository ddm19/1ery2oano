// Programación 2 - Examen Junio 2020         

#include "Book.h"

// Crea una instancia del libro
Book::Book(string title, unsigned int pages, bool prized) {
    this->title = title;
    this->pages = pages;
    this->prized = prized;
}

// Devuelve el título del libro
string Book::getTitle() const {
    return title;
}

// Devuelve el número de páginas del libro
unsigned int Book::getPages() const {
    return pages;
}

// Devuelve true si el libro ha ganado un premio, y falso en caso contrario
bool Book::isPrized() const {
    return prized;
}
