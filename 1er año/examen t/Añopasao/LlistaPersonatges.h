#ifndef LLISTAPERSONATGES_H
#define LLISTAPERSONATGES_H

#include <string>
#include <list>

using namespace std;

class LlistaPersonatges
{
    public:
        LlistaPersonatges();

        void afegir(const string &nom);
        // pre: el nom no existeix; pos: s'afegeix al final;
        void mostrar() const; // pre:-; pos: mostra la llista
        bool existeix(const string& nom); // pre:-; pos: cert si existeix

    private:
        list<string> a_llista;
};

#endif // LLISTAPERSONATGES_H
