#include <iostream>
#include <vector>

using namespace std;

#include "TaulaJugadores.h"

TaulaJugadores::TaulaJugadores()
{
	
}

TaulaJugadores::TaulaJugadores(vector <Jugadora> jugadors)
{
	jugadores=jugadors;
}

bool TaulaJugadores::exist(string nom) const
{
	bool exist=false;
	
	for(unsigned i = 0; jugadores.size() ; i++)
	{
		if(jugadores[i].getName()==nom)
			exist=true;
	}
		
	return exist;
}
void TaulaJugadores::add(Jugadora jugadora)
{	
	jugadores.push_back(jugadora);	
	
}
void TaulaJugadores::canviequip(string equip,string nomjugadora)
{	
	
	for(unsigned i = 0; i<jugadores.size() ; i++)
	{
		if(jugadores[i].getName()==nomjugadora)
			jugadores[i].setEquip(equip);
		
	}
	
}

