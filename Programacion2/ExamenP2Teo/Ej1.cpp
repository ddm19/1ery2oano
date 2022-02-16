#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
using namespace std;

struct cliente
{
	unsigned dni;
	string nomape;
	unsigned compras;	//Cuántas compras ha hecho
	char codigo[3];		//Código de cliente
	float gasto;		//Gasto total en € del cliente
	
	
};

void MontaClientes(vector <string> &datos,vector <cliente> &clientes)
{
	string palabra,dato;
	cliente tempcliente;
	unsigned j=0;
	
	for(unsigned i = 0 ; i<datos.size() ; i++)
	{
		dato=datos[i];
				
		while(dato[0]=='*')
		{
			j=1;
			while(j<dato.length())
			{
				palabra=palabra+dato[j];
				j++;
			}
			tempcliente.nomape=tempcliente.nomape+" "+palabra;	//Nombre y apellidos
			palabra="";			
			i++;
			dato=datos[i];
			
		}
		
		while(dato[0]==';')
		{
			j=1;
			while(j<dato.length())
			{
				palabra=palabra+dato[j];
				j++;
			}
			tempcliente.dni=stoul(palabra);		//Dni
			palabra="";			
			i++;
			dato=datos[i];
			
		}
		while(dato[0]=='_')
		{
			j=1;
			while(j<dato.length())
			{
				palabra=palabra+dato[j];
				j++;
			}
			tempcliente.compras=stoul(palabra);	//compras
			palabra="";			
			i++;
			dato=datos[i];
			
		}
		while(dato[0]=='?')
		{
			j=1;
			while(j<dato.length())
			{
				palabra=palabra+dato[j];
				j++;
			}
			strcpy(tempcliente.codigo,palabra.c_str());	//código
			palabra="";			
			i++;
			dato=datos[i];
			
		}
		while(dato[0]=='$')
		{
			j=1;
			while(j<dato.length())
			{
				palabra=palabra+dato[j];
				j++;
			}
			tempcliente.gasto=tempcliente.gasto+stof(palabra);	//gasto
			palabra="";			
			i++;
			dato=datos[i];
			
		}
		clientes.push_back(tempcliente);
		tempcliente.nomape="";
		tempcliente.dni=0;					//Reset del cliente
		tempcliente.compras=0;
		strcpy(tempcliente.codigo,tempcliente.nomape.c_str());
		tempcliente.gasto=0;
		
	}	
	for(unsigned i = 0; i<clientes.size();i++)
		cout<<clientes[i].nomape<<endl;
	
}

void Parametros(int argc , char *argv[],vector <string> &datos,string &archivosalida)
{
	string error="Error abriendo el archivo";
	string temp;
	
	for(int i = 0  ; i<argc ; i++)
	{
		
		if(strcmp(argv[i],"-i")==0)	//Entrada
		{
			i++;
			
			ifstream archivoentrada(argv[i]);
			if(!archivoentrada.is_open())
				throw(error);
			else
			{
				while(archivoentrada >> temp)
				{
					datos.push_back(temp);		//almacenaje de datos en vector
					
				}
				
			}
			archivoentrada.close();
		}
		if(strcmp(argv[i],"-o")==0)
		{
			i++;
			archivosalida=argv[i];
		}
		
	}
	
	
}


int main(int argc , char *argv[])
{
	vector <string> datos;
	vector <cliente> clientes;
	string archivosalida;
	try
	{
		Parametros(argc,argv,datos,archivosalida);
	}
	catch(string error)
	{
		cout<<error<<endl;
	}
	
	MontaClientes(datos,clientes);
	
	
	return 0;
}
