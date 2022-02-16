#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

ifstream LeeArchivos (string name)	//Leo el archivo y lanzo error si no existe
{
	ifstream ficheroLec;
	string error="Error Abriendo el archivo de texto";

	ficheroLec.open(name);
	if (!ficheroLec.is_open())
		throw(error);

	return ficheroLec;
}

unsigned CuentaPalabras (string palabra,vector <string> palabras)
{
	unsigned contador=0;
	
	for(unsigned i = 0; i<palabras.size() ; i++)
	{
		if(palabra==palabras[i])
			contador++;
	}
	
	return contador;
}

bool ExisteRepetido (string palabra, vector <string> palabras)
{
	bool encontrado=false;
	
	for(unsigned i = 0 ; i<palabras.size() ; i++)
	{
		if(palabra==palabras[i])
			encontrado=true;
	}
	
	return encontrado;
}

string Donlimpio(string palabra)
{
	string nueva="";
	
	for(unsigned i = 0; i<palabra.length() ; i++)
	{
		if(isupper(palabra[i]))
			palabra[i]=tolower(palabra[i]);
			
		if(isalnum(palabra[i]))
			nueva=nueva+palabra[i];
		
	}
	
	return nueva;
}

int main(int argc,char *argv[])
{
	ifstream archivo;
	string name;
	string palabra;
	vector <string> repetidos;
	vector <string> palabras;
	
	cin>>name;
	
	try 
	{
		archivo=LeeArchivos(name);
		
		while(archivo >> palabra)
		{
			palabra=Donlimpio(palabra);
			//cout<<palabra<<endl;
			palabras.push_back(palabra);	//paso el archivo a vector
		}
	}
	catch (string error)
	{
		cout << error << endl;
	}
	
	for(unsigned i = 0; i<palabras.size() ; i++)
	{
		
		if(!ExisteRepetido(palabras[i],repetidos))
		{
			cout<<palabras[i]<<"->"<<CuentaPalabras(palabras[i],palabras)<<endl;
			repetidos.push_back(palabras[i]);
		}	
	}

return 0;
}
