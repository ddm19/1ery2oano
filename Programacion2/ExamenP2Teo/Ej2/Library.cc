// Programación 2 - Examen Junio 2020         

#include <iostream>
using namespace std;

#include "Library.h"

unsigned int Library::nextReaderId = 1;

// Devuelve la posición del autor en el vector authors, o -1 si no lo encuentra
int Library::searchAuthor(string authorName) const {
    for (unsigned i = 0; i < authors.size(); i++) {
        if (authors[i].getName() == authorName) {
            return i;
        }
    }
    return -1;
}

// Devuelve la posición del libro en el vector books, o -1 si no lo encuentra
int Library::searchBook(string bookTitle) const {
    for (unsigned i = 0; i < books.size(); i++) {
        if (books[i].getTitle() == bookTitle) {
            return i;
        }
    }
    return -1;
}

// Devuelve la posición del lector en el vector readers, o -1 si no lo encuentra
int Library::searchReader(unsigned int readerId) const {
    for (unsigned i = 0; i < readers.size(); i++) {
        if (readers[i].getId() == readerId) {
            return i;
        }
    }
    return -1;
}

// Crea una instancia de la biblioteca
Library::Library(string name) {
    this->name = name;
}

// Crea un autor y lo guarda en el vector de autores
// Lanza una excepción si ya hay un autor con ese nombre
void Library::createAuthor(string authorName) {
    int pos = searchAuthor(authorName);
    if (pos != -1) {
        throw author_exists;
    }
    Author a(authorName);
    authors.push_back(a);
}

// Crea un libro y lo guarda en el vector de libros,
//   guardando también el título del libro en el autor
// Si el autor no existe o ya hay otro libro
//   con el mismo título lanza una excepción
void Library::createBook(string authorName, string bookTitle,
                         unsigned int pages, bool prized) {
    int pos = searchAuthor(authorName);
    if (pos == -1) {
        throw unknown_author;
    }
    int pos2 = searchBook(bookTitle);
    if (pos2 != -1) {
        throw book_exists;
    }
    Book b(bookTitle, pages, prized);
    books.push_back(b);
    authors[pos].addBook(bookTitle);
}

// Crea un lector (persona que puede sacar libros prestados)
unsigned int Library::createReader(string readerName) {
    unsigned int id = nextReaderId++;
    Reader r(readerName, id);
    readers.push_back(r);
    return id;
}

// Crea un préstamo de libro, asignándolo a un lector
// Lanza una excepción si el libro o el lector no existen
void Library::lendBook(string bookTitle, unsigned int readerId) {
    int pos = searchBook(bookTitle);
    if (pos == -1) {
        throw unknown_book;
    }
    int pos2 = searchReader(readerId);
    if (pos2 == -1) {
        throw unknown_reader;
    }
    readers[pos2].createLending(bookTitle);
}

// Marca un préstamo de libro como devuelto
// Lanza una excepción si el libro o el lector no existen
void Library::returnBook(string bookTitle, unsigned int readerId) {
    int pos = searchBook(bookTitle);
    if (pos == -1) {
        throw unknown_book;
    }
    int pos2 = searchReader(readerId);
    if (pos2 == -1) {
        throw unknown_reader;
    }
    readers[pos2].cancelLending(bookTitle);
}

string Library::report () const
{
	string autormax,autortemp;
	vector <Lending> librospresta;
	vector <string> libros;
	unsigned prestamostemp=0,prestamosmax=0;
	
	for(unsigned i = 0; i<authors.size() ; i++)	//Para cada autor
	{
		autortemp=authors[i].getName();
		libros=authors[i].getBooks();
		for(unsigned j=0 ; j<readers.size() ; j++)
		{
			librospresta=readers[j].getlendings();
			for(unsigned k = 0; k<librospresta.size() ; k++)	//Y cada préstamo
			{
				
				
				for(unsigned l=0; l<libros.size() ; l++)
				{
					if(libros[l]==librospresta[k].getBookTitle())	// Comparo si el libro prestado es uno de los del autor
						prestamostemp++;
				}
				
				
			}
			
		}
		
		if(prestamostemp>prestamosmax)		//Si el total de libros prestados de El autor actual es mayor al anterior, el máximo es el actual
		{
			cout<<prestamosmax<<" "<<prestamostemp<<endl;
			autormax=autortemp;
			prestamosmax=prestamostemp;
			
		}
		
		prestamostemp=0;
	}
	
	return autormax;
}
