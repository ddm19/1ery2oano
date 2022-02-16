/*
   ENTRADA: aquest programa rep un conjunt de fitxers que estan en un cert directori,
            tots ells amb el mateix format.
   SORTIDA: el progama processa la informació i acumula els totals dels
            jugadors, personatges per tal de...(no completat! -> de moment, només mostra les dades)
*/

#include <iostream>

#include <string>
#include <fstream>


using namespace std;


#include "DadesJugadors.h"
#include "DadesPersonatges.h"

#include "Registre.h"


bool quedenFitxers() {
// pre: cert
// post: retorna fals si ja no queden fitxers en el directori
// detall: es una simulació, retorna fals a la tercera.

    cerr << "queden fitxers no fet" << endl;
    static int auxiliar = 0;

    auxiliar++;

    return auxiliar<3;
}


string obtenirPrimerFitxer() {
// pre: queden fitxers
// post: retorna el nom del fitxer mes antic
// detall: es una simulacio, retorna sempre els mateixos valors

    static string nom;

    if (nom=="")
        nom = "primer.txt";
    else
        nom = "segon.txt";
    cerr << "obtenir el fitxer: " << nom << endl;
    return nom;
}


void esborraPrimerFitxer(const string &nom) {
// pre: cert (o queden fitxers)
// post: esborra el fitxer mes antic (o no fa res si no en queden?)
// detall: es una simulacio, no fa res...

    cerr << "esborra el fitxer " << nom << endl;
}


void processarFitxer(const string & nom, DadesJugadors & jugadors, DadesPersonatges & personatges) {
// pre: existeix un fitxer de nom indicat
// post: acumula la informacio del fitxer en les estructures jugadors i personatges
// si el fitxer no existeix o no es pot obrir, surt el missatge "NO S'HA OBERT EL FITXER..."

    ifstream fitxer(nom.c_str());

    if (fitxer.is_open()) {
        Registre element;

        fitxer >> element;
        while (not fitxer.eof()) {
            jugadors.afegir(element);
            personatges.afegir(element);
            fitxer >> element;
        }
        fitxer.close();
    } else
        cerr << "NO S'HA OBERT EL FITXER " << nom << endl;
}


void tractarValors(const DadesJugadors & jugadors, const DadesPersonatges & personatges) {
// pre: cert
// post: mostra el contingut de les estructures per pantalla
// detall: es una possible manera de tractar la informacio, caldria adaptar-ho a l'enunciat (quan es completi)

    cout << " -- JUGADORS --"  << endl;
    jugadors.mostrar();
    cout << endl;
    cout << " -- PERSONATGES --"  << endl;
    personatges.mostrar();
    cout << endl;
}


int main()
{
    DadesJugadors jugadors;
    DadesPersonatges personatges;

    while (quedenFitxers()) {
        string nom = obtenirPrimerFitxer();
        processarFitxer(nom, jugadors, personatges);
        esborraPrimerFitxer(nom);
    }
    tractarValors(jugadors, personatges);

    return 0;
}



/*

comencem
queden fitxers no fet
nom:primer.txt
esborra el fitxer primer.txt
queden fitxers no fet
nom:segon.txt
esborra el fitxer segon.txt
queden fitxers no fet
 -- JUGADORS --
A:Clacal J:1 P:416 T:80 - Clara Calavera
Personatges: Miarge
A:Empty J:6 P:834 T:1201 - Empar Tirado
Personatges: Castuic Ocnate
A:Full J:6 P:832 T:1346 - Francesc Ullastre
Personatges: Banagolre
A:Rain J:4 P:802 T:1019 - Ramon Infant
Personatges: Miarge Castuic

 -- PERSONATGES --
NOM:Banagolre JOCS:6 PUNTS:832
NOM:Castuic JOCS:4 PUNTS:628
NOM:Miarge JOCS:3 PUNTS:870
NOM:Ocnate JOCS:4 PUNTS:554 2884


*/
