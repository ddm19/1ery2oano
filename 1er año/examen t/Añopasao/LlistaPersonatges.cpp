#include <iostream>

using namespace std;

#include "LlistaPersonatges.h"

LlistaPersonatges::LlistaPersonatges()
{

}


void LlistaPersonatges::afegir(const string& nom)
{
    a_llista.push_back(nom);
}


void LlistaPersonatges::mostrar() const
{
    list<string> aux = a_llista;
    list<string>::iterator it = aux.begin();
    while (it != aux.end()) {
        cout << *it << ' ';
        it++;
    }
    cout << endl;
}

bool LlistaPersonatges::existeix(const string& nom)
{
    list<string>::iterator it = a_llista.begin();
    while (it!=a_llista.end() and *it!=nom)
        it++;
    return it!=a_llista.end();
}


