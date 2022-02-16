// Programación 2 - Examen Junio 2020         

#include "Author.h"

// Crea una instancia del autor
Author::Author(string name) {
    this->name = name;
}

// Devuelve el nombre del autor
string Author::getName() const {
    return name;
}

// Añade un libro al autor, sólo guarda el título del libro
void Author::addBook(string bookTitle) {
    books.push_back(bookTitle);
}

// Devuelve los títulos de todos los libros escritos por el autor
// Para recuperar la instancia del libro debes usar Library::searchBook(bookTitle)
vector<string> Author::getBooks(void) const {
    return books;
}
