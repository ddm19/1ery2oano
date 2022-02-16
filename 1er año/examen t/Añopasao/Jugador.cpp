#include "Jugador.h"


Jugador::Jugador() {
// pre: -
// post: jugador buit
    a_alias = a_nomComplet = "";
    a_nPartides = a_nPunts = a_totalTemps = 0;
}


Jugador::Jugador(const string& alias) {
// pre: -
// post: jugador a partir de l'alias
    a_alias = alias;
    a_nomComplet = "";
    a_nPartides = a_nPunts = a_totalTemps = 0;
}

Jugador::Jugador(const string& alias, const string& nomJugador, int punts, int temps, const string &nomPersonatge) {
// pre: punts, temps >=0
// post: jugador a partir dels valors
    a_alias = alias;
    a_nomComplet = nomJugador;
    a_nPartides = 1;
    a_nPunts = punts;
    a_totalTemps = temps;
    a_personatges.afegir(nomPersonatge);
}


bool Jugador::operator==(const Jugador& jugador) const {
// pre: -
// post: cert si tenen el mateix alies

    return a_alias == jugador.a_alias;
}



bool Jugador::operator!=(const Jugador& jugador) const {
// pre: -
// post: cert si tenen alias diferents

    return a_alias != jugador.a_alias;
}




bool Jugador::operator<(const Jugador& jugador) const
{
    return a_alias < jugador.a_alias;
}


void Jugador::actualitza(const Registre& registre)
{
    Jugador jugador = registre.obtJugador();
    string nom = registre.obtNomPersonatge();

    a_nPartides += jugador.a_nPartides;
    a_nPunts += jugador.a_nPunts;
    a_totalTemps += jugador.a_totalTemps;
    if (not a_personatges.existeix(nom))
        a_personatges.afegir(nom);
}



string Jugador::obtAlias() const
{
    return a_alias;
}


void Jugador::mostrar() const
{
    cout << "A:" << a_alias << " J:" << a_nPartides << " P:" << a_nPunts << " T:" << a_totalTemps << " " << a_nomComplet << endl;
    cout << "Personatges: ";
    a_personatges.mostrar();
}


