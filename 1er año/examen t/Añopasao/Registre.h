#ifndef REGISTRE_H
#define REGISTRE_H

#include <iostream>
#include <string>

using namespace std;

class Registre;
#include "Jugador.h"
#include "Personatge.h"


/********************************************************************
 classe registre

 Descripció: permet tractar la informacio d'una linia del fitxers
 Invariant: els enters són no negatius

 ********************************************************************/


class Registre
{
    public:
        Registre(); // pre: -; post: registre buit

        Jugador obtJugador() const; // pre: -; post: retorna el jugador
        Personatge obtPersonatge() const; // pre: -; post: retorna el personatge
        string obtNomPersonatge() const; // pre: -; post: retorna el nom del personatge
        friend istream &operator >>(istream &i, Registre &registre);
        // pre: -; post: posa les dades de teclat / fitxer en el registre

    private:
        int a_idPartida;
        string a_nomPersonatge;
        int a_punts;
        int a_temps;
        string a_alias;
        string a_nomJugador;
};

#endif // REGISTRE_H
