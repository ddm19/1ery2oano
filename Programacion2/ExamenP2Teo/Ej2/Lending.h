// Programación 2 - Examen Junio 2020         

#ifndef __LENDING__
#define __LENDING__

#include <string>

using namespace std;

class Lending {
    private:
        bool returned;
        string bookTitle;
    public:
        Lending(string bookTitle);
        string getBookTitle() const;
        bool isReturned() const;
        void setReturned(bool value);
};

#endif
