#ifndef LLISTANOMS_H
#define LLISTANOMS_H

#include <string>
#include <vector>
#include "Jugadora.h"
using namespace std;


class LlistaNoms
{
    public:
        LlistaNoms();
        bool exist(string nom);
        void add(string nom);
        void remove(string nom);

    private:
		vector<string> tranferibles;
};

#endif // LLISTANOMS_H
