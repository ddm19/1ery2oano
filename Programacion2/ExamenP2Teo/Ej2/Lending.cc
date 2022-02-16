// Programación 2 - Examen Junio 2020         

#include "Lending.h"

// Crea una instancia de préstamo, el libro se referencia por su título
Lending::Lending(string bookTitle) {
    this->bookTitle = bookTitle;
    this->returned = false;
}

// Devuelve el título del libro
// Para recuperar la instancia del libro debes usar Library::searchBook(bookTitle)
string Lending::getBookTitle() const {
    return bookTitle;
}

// Devuelve true si el libro se ha devuelto, y falso en caso contrario
bool Lending::isReturned() const {
    return returned;
}

// Establece si el libro prestado se ha devuelto o no
void Lending::setReturned(bool value) {
    returned = value;
}
