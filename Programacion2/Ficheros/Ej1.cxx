#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream fichero("Fichero");
	ofstream FICHERO("FICHERO");
	string palabra;
	
	if(fichero.is_open() && FICHERO.is_open())
	{
		while(getline(fichero,palabra))
		{
			for(unsigned i = 0; i<palabra.length();i++)
				palabra[i]=toupper(palabra[i]);
			FICHERO<<palabra;
		}
		fichero.close();
	}
	else
		cout<<"Error";
	
	
	
	
	return 0;
}

