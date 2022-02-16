// Programación 2 - Examen Junio 2020         

#include <iostream>

using namespace std;

#include "Library.h"

void createData(Library &);

int main() {
    Library obj("British Library");
    createData(obj);
    cout<<obj.report()<<endl;
}

// Crea datos de ejemplo para probar las funcionalidades
void createData(Library &obj) {
    obj.createReader("James M. Walker");
    obj.createReader("Brent J. Halladay");
    obj.createReader("Valencia L. Edwards");
    obj.createReader("Robert S. Evans");
    obj.createReader("Rosalina J. Lugo");
    obj.createReader("Ralph E. Dumas");
    obj.createReader("Della M. Bartley");
    obj.createReader("Annette R. Dixon");
    obj.createReader("Sally W. Woods");
    obj.createReader("Larry D. Landry");

    obj.createAuthor("Cormac McCarthy");
    obj.createAuthor("Jane Austen");

    obj.createAuthor("Mary Shelley");
    obj.createBook("Mary Shelley", "Frankenstein", 250, true);
    obj.lendBook("Frankenstein", 1);
    obj.lendBook("Frankenstein", 2);
    obj.lendBook("Frankenstein", 3);

    obj.createAuthor("Isaac Asimov");
    obj.createBook("Isaac Asimov", "Foundation", 132, false);
    obj.lendBook("Foundation", 2);
    obj.lendBook("Foundation", 3);
    obj.lendBook("Foundation", 4);
    obj.lendBook("Foundation", 5);
    obj.returnBook("Foundation", 3);
    obj.returnBook("Foundation", 4);
    obj.returnBook("Foundation", 5);
    obj.createBook("Isaac Asimov", "The Caves of Steel", 187, false);
    obj.lendBook("The Caves of Steel", 6);

    obj.createAuthor("Stephen King");
    obj.createBook("Stephen King", "It", 640, false);
    obj.lendBook("It", 3);
    obj.lendBook("It", 4);
    obj.returnBook("It", 3);
    obj.returnBook("It", 4);

    obj.createAuthor("J. K. Rowling");
    obj.createBook("J. K. Rowling", "Harry Potter and the Philosopher's Stone", 348, true);
    obj.lendBook("Harry Potter and the Philosopher's Stone", 7);
    obj.lendBook("Harry Potter and the Philosopher's Stone", 8);
    obj.lendBook("Harry Potter and the Philosopher's Stone", 9);
    obj.createBook("J. K. Rowling", "Harry Potter and the Chamber of Secrets", 412, false);
    obj.lendBook("Harry Potter and the Chamber of Secrets", 3);
    obj.lendBook("Harry Potter and the Chamber of Secrets", 4);
    obj.lendBook("Harry Potter and the Chamber of Secrets", 5);
    obj.returnBook("Harry Potter and the Chamber of Secrets", 3);
    obj.returnBook("Harry Potter and the Chamber of Secrets", 4);
    obj.returnBook("Harry Potter and the Chamber of Secrets", 5);

    obj.createAuthor("Dan Brown");
    obj.createBook("Dan Brown", "The Da Vinci Code", 376, true);
    obj.lendBook("The Da Vinci Code", 1);
    obj.lendBook("The Da Vinci Code", 2);
    obj.lendBook("The Da Vinci Code", 3);
    obj.lendBook("The Da Vinci Code", 4);
    obj.lendBook("The Da Vinci Code", 5);
}
