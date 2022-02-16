#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <iostream>

using namespace std;

/********************************************************************
 classe jugador

 Descripció: permet tractar la informacio d'un jugador

 ********************************************************************/

#include "LlistaPersonatges.h"
class Jugador;
#include "Registre.h"

class Jugador
{
    public:
        Jugador(); // pre: -; post: jugador buit
        Jugador(const string &alias);
        // pre: -; post: jugador amb una alias i tot buit
        Jugador(const string &alias, const string &nomJugador, int punts, int temps, const string &nomPersonatge);
        // pre: punts, temps >=0; post: jugador a partir dels valors


        bool operator==(const Jugador & jugador) const; //pre: -; post: cert si tenen el mateix alies
        bool operator!=(const Jugador & jugador) const; //pre: -; post: cert si tenen alias diferents
        bool operator <(const Jugador & jugador)
        const; //pre: -; post: cert si tenen el mateix alies

        string obtAlias() const; // pre:-; pos: retorna l'alias;
        void actualitza(const Registre & registre);  //pre: -; post: acumula el paràmetre a l'objecte

        void mostrar() const; // pre: -; post: mostra per pantalla les dades del jugador
    private:
        string a_alias;
        string a_nomComplet;
        int a_nPartides;
        int a_nPunts;
        int a_totalTemps;
        LlistaPersonatges a_personatges;
};

#endif // JUGADOR_H
