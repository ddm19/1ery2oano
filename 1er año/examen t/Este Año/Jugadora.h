#ifndef JUGADORA_H
#define JUGADORA_H

#include <string>
#include <fstream>
#include <string>

using namespace std;


#include "Data.h"

class Jugadora
{
    public:
        Jugadora();
        // pre:cert; pos:inicialitza els atributs
        
        Jugadora(const string & nom, const string & equip = "", const Data & data = Data(), const double altura = 0.0);
		// pre:cert; pos: inicialitza els atributs amb els valors donats
		 
        void mostrar() const;
        // pre:cer; pos:mostra una jugadora per pantalla

        bool operator==(const Jugadora & jugadora) const;
        // pre:cert; pos:cert si tenen el mateix nom
        
        bool operator!=(const Jugadora & jugadora) const;
        // pre:cert; pos:cert si tenen nom diferent
        
        bool operator< (const Jugadora & jugadora) const;
		// pre:cert; cert: ceir si el és menor que el de jugadora
		
        void llegir(ifstream & f);
        // pre:fitxer obert; pos: llegeix una jugadora o EOF
        string getName() const { return a_nom; } ;
        void setEquip(string equip) { a_equip=equip; };

    private: // no es poden canviar els atributs
        string a_nom;
        string a_equip;
        Data a_data_n;
        double a_altura;
};

#endif // JUGADORA_H
