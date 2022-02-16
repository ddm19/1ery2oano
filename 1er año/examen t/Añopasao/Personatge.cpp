#include "Personatge.h"



Personatge::Personatge() {
// pre: -
// post: personatges buit
    a_nom = "";
    a_nPartides = a_nPunts = a_nJugadors = 0;
}



Personatge::Personatge(const string &nom, int punts) {
// pre: punts>=0
// personatge amb els valors donats
    a_nom = nom;
    a_nPartides = a_nJugadors = 1;
    a_nPunts = punts;
}


bool Personatge::operator==(const Personatge& personatge) const {
// pre: -
// post: cert si tenen el mateix nom
    return a_nom == personatge.a_nom;
}



bool Personatge::operator!=(const Personatge& personatge) const {
// pre: -
// post: cert si tenen noms diferents
    return a_nom != personatge.a_nom;
}



bool Personatge::operator<(const Personatge& personatge) const {
// pre: -
// post: cert si es mes petit que el parametre

    return a_nom < personatge.a_nom;
}



string Personatge::obtNom() const
{
    return a_nom;
}

void Personatge::actualitza(const Personatge& personatge)
{
    a_nPartides += personatge.a_nPartides;
    a_nPunts += personatge.a_nPunts;
}



void Personatge::actualitza(const Registre& element)
{
    Personatge personatge = element.obtPersonatge();
    a_nPartides++;
    a_nPunts += personatge.a_nPunts;
}

ostream & operator <<(ostream &o, const Personatge &personatge) {
// pre: -
//7post: mostra per pantalla/fitxer les dades del personatge
    o << "NOM:" << personatge.a_nom << " JOCS:" << personatge.a_nPartides
      << " PUNTS:" << personatge.a_nPunts;

    return o;
}

