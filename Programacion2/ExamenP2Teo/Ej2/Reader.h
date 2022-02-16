// Programación 2 - Examen Junio 2020         

#ifndef __READER__
#define __READER__

#include <string>
#include <vector>

using namespace std;

#include "Lending.h"

// Excepciones que puede lanzar la clase
enum ExceptionsReader {
    book_not_returned,
    book_not_borrowed,
    book_already_returned
};

class Reader {
  private:
    unsigned int id;
    string name;
    vector<Lending> lendings;
    int searchLending(string bookTitle);

  public:
    Reader(string name, unsigned int id);
    string getName() const;
    unsigned int getId() const;
    void createLending(string bookTitle);
    vector<Lending> getlendings() const {return lendings;};
    void cancelLending(string bookTitle);
};

#endif
