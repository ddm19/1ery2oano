#include "Registre.h"


Registre::Registre() {
// pre: -
// post: registre buit

    a_idPartida = a_punts = a_temps = 0;
    a_nomPersonatge = a_alias = a_nomJugador = "";
}



Jugador Registre::obtJugador() const {
// pre: -
// post: retorna un jugador

    return Jugador(a_alias, a_nomJugador, a_punts, a_temps, a_nomPersonatge);
}

Personatge Registre::obtPersonatge() const {
// pre: -
// post: retorna un personatge

    return Personatge(a_nomPersonatge, a_punts);
}


string Registre::obtNomPersonatge() const
{
    return a_nomPersonatge;
}


istream &operator >>(istream & i, Registre & registre) {
// pre: -
// post: posa les dades de teclat / fitxer en el registre

    i >> registre.a_idPartida
      >> registre.a_nomPersonatge
      >> registre.a_punts
      >> registre.a_temps
      >> registre.a_alias;

    char aux;
    i.get(aux); // espai que separa alias de nom jugador
    getline(i, registre.a_nomJugador);

    return i;
}


