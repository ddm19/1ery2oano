// Programación 2 - Examen Junio 2020         

#include "Reader.h"

// Devuelve la posición del préstamo en el vector lendings
//   para el libro con título bookTitle, o -1 si no lo encuentra
int Reader::searchLending(string bookTitle) {
    for (unsigned i = 0; i < lendings.size(); i++) {
        if (lendings[i].getBookTitle() == bookTitle) {
            return i;
        }
    }
    return -1;
}

// Crea una instancia de la clase Reader (persona que puede sacar libros prestados)
// El identificador lo gestiona la clase Library
Reader::Reader(string name, unsigned int id) {
    this->name = name;
    this->id = id;
}

// Devuelve el nombre del lector
string Reader::getName() const {
    return name;
}

// Devuelve el identificador del lector
unsigned int Reader::getId() const {
    return id;
}

// Crea un préstamo para el lector y el libro que se recibe como parámetro
// Lanza una excepción si el lector ya tiene ese libro en préstamo
void Reader::createLending(string bookTitle) {
    int pos = searchLending(bookTitle);
    if (pos != -1 && !lendings[pos].isReturned()) {
        throw book_not_returned;
    }
    if (pos != -1 && lendings[pos].isReturned()) {
        lendings[pos].setReturned(false);
    } else {
        Lending l(bookTitle);
        lendings.push_back(l);
    }
}

// Cancela un préstamo, marcándolo como devuelto
// Lanza una excepción si el libro no se ha cogido en préstamo
//   o si el lector ya lo ha devuelto
void Reader::cancelLending(string bookTitle) {
    int pos = searchLending(bookTitle);
    if (pos == -1) {
        throw book_not_borrowed;
    }
    if (pos != -1 && lendings[pos].isReturned()) {
        throw book_already_returned;
    }
    lendings[pos].setReturned(true);
}
