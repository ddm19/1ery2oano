#include "DadesPersonatges.h"

DadesPersonatges::DadesPersonatges()
{
    a_nDades = 0;
}

void DadesPersonatges::afegir(const Registre& element) {
// pre: -
// post: acumula els valors d'un registre
    Personatge personatge = element.obtPersonatge();
    int posicio = cerca(personatge);

    if (posicio < 0) {
        if (a_nDades < MAX_PERSONATGES) {
            int i = a_nDades;
            while (i > 0 and personatge < a_tDades[i-1]) {
                a_tDades[i] = a_tDades[i-1];
                i--;
            }
            a_tDades[i] = personatge;
            a_nDades++;
        } else
            cerr << "NO HI HA ESPAI PER MES PERSONATGES" << endl;
    } else {
        a_tDades[posicio].actualitza(personatge);
    }
}


void DadesPersonatges::mostrar() const {
// pre: -
// post: mostra el conjunt
    for (int i=0; i<a_nDades; i++)
        cout << a_tDades[i] << endl;
    cout << endl;
}



bool DadesPersonatges::existeix(const Personatge& personatge) const {
// pre: -
// post: cert si pertany al conjunt

    return (cerca(personatge) != NO_TROBAT);
}



int DadesPersonatges::cerca(const Personatge& personatge) const {
// pre: -
// post: retorna -1 o la posicio on es troba
    int esq = 0;
    int dre = a_nDades-1;
    bool trobat = false;
    int mig = 0;


    while (not trobat and esq<=dre) {
        mig = (esq+dre) / 2;
        if (personatge < a_tDades[mig])
            dre = mig-1;
        else if (a_tDades[mig] < personatge)
            esq = mig+1;
        else
            trobat = true;
    }
    if (trobat)
        return mig;
    else
        return NO_TROBAT;
}


