#include <iostream>
#include <limits>
#include <iomanip>


using namespace std;


#include "Jugadora.h"

Jugadora::Jugadora()
{
    a_altura = 0.0;
}


Jugadora::Jugadora(const string& nom, const string& equip, const Data& data, const double altura)
{
    a_nom = nom;
    a_equip = equip;
    a_data_n = data;
    a_altura = altura;
}

void Jugadora::mostrar() const
{
    cout << "Nom: " << a_nom << " (" << a_equip << "), dNaix: ";
    a_data_n.mostrar(1);
    cout << ", A: " << fixed << setprecision(2) << a_altura << " m" << endl;
}


bool Jugadora::operator==(const Jugadora& jugadora) const
{
    return a_nom == jugadora.a_nom;
}

bool Jugadora::operator!=(const Jugadora& jugadora) const
{
    return a_nom != jugadora.a_nom;
}

bool Jugadora::operator<(const Jugadora& jugadora) const
{
    return a_nom < jugadora.a_nom;
}

void Jugadora::llegir(ifstream& f)
{
    getline(f, a_nom);
    if (not f.eof()) {
        int dia, mes, any;
        getline(f, a_equip);
        f >> dia >> mes >> any >> a_altura;
        a_data_n = Data(dia, mes, any);
        f.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}



