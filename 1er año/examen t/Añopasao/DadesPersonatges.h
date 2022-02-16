#ifndef DADESPERSONATGES_H
#define DADESPERSONATGES_H

#include "Registre.h"
#include "Personatge.h"

/********************************************************************
 classe dades personatges

 Objectiu: permet tractar la informacio d'un conjunt de personatges
 Invariant: els personatges estan ordenats de manera creixent per nom,

 ********************************************************************/

class DadesPersonatges
{
    public:
        DadesPersonatges(); //pre: -; post: estructura buida;

        void mostrar() const; //pre: -; post: mostra els personatges
        bool existeix(const Personatge & personatge) const; //pre: -; post: cert si està donat d'alta

        void afegir(const Registre & element); //pre: -; post: acumula els valors d'un registre

    private:
        static const int MAX_PERSONATGES = 150;
        static const int NO_TROBAT = -1;

        Personatge a_tDades[MAX_PERSONATGES];
        int a_nDades;

        int cerca(const Personatge & personatge) const; // pre: -; post: retorna NO TROBAT o la posicio on es troba
};

#endif // DADESPERSONATGES_H
