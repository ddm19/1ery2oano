#ifndef DADESJUGADORS_H
#define DADESJUGADORS_H

 #include <vector>

 using namespace std;

#include "Jugador.h"
#include "Registre.h"

/********************************************************************
 classe dades jugadors

 Objectiu: permet tractar la informacio d'un conjunt de jugadors
 Invariant: els personatges estan posats ordenadament en una taula
            dinàmica que s'amplia.

 ********************************************************************/


class DadesJugadors
{
    public:
        DadesJugadors(); //pre: -; post: estructura buida

        bool existeix(const Jugador & jugador) const; // pre: -; post: cert si està donat d'alta
        void mostrar() const; // pre: -; post: mostra les dades guardades per pantalla

        void afegir(const Registre & element); //pre: -; post: fa l'alta i/o acumula les dades d'un registre
    private:
        static const int MIDA_INICIAL = 100;
        static const int NO_TROBAT = -1;

        vector<Jugador> a_vDades;

        int cerca(const Jugador & jugador) const;  // pre: -; post: retorn la posicio o NO TROBAT si no existeix
};

#endif // DADESJUGADORS_H
