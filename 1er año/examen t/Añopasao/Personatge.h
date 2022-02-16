#ifndef PERSONATGE_H
#define PERSONATGE_H

#include <string>
#include <iostream>

using namespace std;

/********************************************************************
 classe personatge

 Descripció: permet tractar la informacio d'un personatge


 ********************************************************************/

class Personatge;
#include "Registre.h"


class Personatge
{
    public:
        Personatge(); //pre: -; post: personatges buit
        Personatge(const string &nomPersonatge, int punts=0);
        // pre: punts=0; personatge amb els valors donats

        bool operator==(const Personatge &personatge) const; //pre: -; post: cert si tenen el mateix nom
        bool operator!=(const Personatge &personatge) const; //pre: -; post: cert si tenen noms diferents
        bool operator<(const Personatge &personatge) const; //pre: -; post: cert si es mes petit que el parametre

        string obtNom() const;
        void actualitza(const Personatge &personatge); //pre: -; post: acumula el paràmetre a l'objecte
        void actualitza(const Registre &element); //pre: -; post: acumula el paràmetre a l'objecte

        friend ostream & operator <<(ostream &o, const Personatge &personatge);
        // pre: -; post: mostra per pantalla/fitxer les dades del personatge

    private:
        string a_nom;
        int a_nPartides;
        int a_nPunts;
        int a_nJugadors;
};

#endif // PERSONATGE_H
