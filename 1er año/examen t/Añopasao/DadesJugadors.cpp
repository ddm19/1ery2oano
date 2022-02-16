#include "DadesJugadors.h"

DadesJugadors::DadesJugadors()
{

}


void DadesJugadors::afegir(const Registre& element) {
// pre: -
// post: acumula un registra al conjunt
    Jugador jugador = element.obtJugador();

    int pos = cerca(jugador);

    if (pos != NO_TROBAT) { // trobat
        a_vDades[pos].actualitza(element);
    }
    else { // no trobat -> alta
        int j = a_vDades.size();
        a_vDades.push_back(Jugador());
        while (j>0 and jugador < a_vDades[j-1]) {
            a_vDades[j] = a_vDades[j-1];
            j--;
        }
        a_vDades[j] = jugador;
    }
}


bool DadesJugadors::existeix(const Jugador& jugador) const {
// pre: -
// post: cert si pertanny al conjunt

    return cerca(jugador) != NO_TROBAT;
}




void DadesJugadors::mostrar() const {
// pre: -
// post: mostra el conjunt per pantalla

    int a_nDades = a_vDades.size();
    for (int i=0; i<a_nDades; i++) {
        a_vDades[i].mostrar();
    }
}





int DadesJugadors::cerca(const Jugador& jugador) const {
// pre: -
// post: retorna la posicio on es troba o NO_TROBAT
    int mig;
    bool trobat = false;
    int esq = 0, dre = a_vDades.size()-1;
    while (esq<=dre and not trobat) {
        mig = (esq+dre) / 2;
        if (a_vDades[mig] == jugador)
            trobat = true;
        else if (jugador < a_vDades[mig])
            dre = mig-1;
        else
            esq = mig+1;
    }
    if (not trobat)
        return NO_TROBAT;
    else
        return mig;
}


