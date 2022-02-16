#ifndef TAULAJUGADORES_H
#define TAULAJUGADORES_H


#include "Jugadora.h"
#include <vector>

class TaulaJugadores
{
    public:
        TaulaJugadores();
        TaulaJugadores(vector <Jugadora> jugadors);
        bool exist(const string nom) const;
        void add(Jugadora jugadora);
        void canviequip(string equip,string nomjugadora);

    private:
		vector<Jugadora> jugadores;
        static const int NO_TROBAT = -1;

};

#endif // TAULAJUGADORES_H
