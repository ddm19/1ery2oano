#include <iostream>
#include <cstring>
#include <time.h>
#include <stdio.h>
using namespace std;

const int MAX=50; //NUMERO MAXIMO DE GATOS QUE PUEDE TENER LA ABUELA TERESA

typedef char TCadena[10];

struct TFecha{
int dia;
int mes;
int anyo;
};

struct TMascota{
TCadena nombre;
TFecha fec;
};

typedef TMascota TGatos[MAX];

void iniciaMininos(TGatos, int &tam);
void MuestraGato(TGatos mininos);
void ComprobarVacunas(TGatos mininos,TFecha actual);

int main(){
TGatos mininos;
int tam,eleccion,veces=3;

time_t t;
struct tm *tlocal;
int dia, mes,anyo;				//FECHA ACTUAL
t=time(NULL);
tlocal=localtime(&t);
dia=tlocal->tm_mday;
mes=tlocal->tm_mon+1;
anyo=tlocal->tm_year+1900;

TFecha actual;
actual.dia=dia;
actual.mes=mes;
actual.anyo=anyo;

iniciaMininos(mininos, tam);

do
{
cout<<" MENU:\n1.Registrar Nuevo Gato\n2.Mostrar Gatos a Vacunar\n3.Listado de Gatos\n4.Salir\n";
		 
cin>>eleccion;
	switch (eleccion)
	{	
		case 1:
			veces++;
			cout<<"Inserte el Nombre del gato: ";cin>>mininos[veces].nombre;
			cout<<"Inserte la fecha de adopción del gato Día, mes y año: ";cin>>mininos[veces].fec.dia>>mininos[veces].fec.mes>>mininos[veces].fec.anyo;
			
			break;
		case 2:
			ComprobarVacunas(mininos,actual);
			break;
		case 3:
		MuestraGato(mininos);
	}
	}while(eleccion!=4);
}





void iniciaMininos(TGatos mininos, int &tam){
strcpy(mininos[0].nombre,"Manolo");
mininos[0].fec.dia=1;
mininos[0].fec.mes=1;
mininos[0].fec.anyo=2015;

strcpy(mininos[1].nombre,"Kira");
mininos[1].fec.dia=22;
mininos[1].fec.mes=12;
mininos[1].fec.anyo=2018;

strcpy(mininos[2].nombre,"Peluso");
mininos[2].fec.dia=5;
mininos[2].fec.mes=3;
mininos[2].fec.anyo=2017;

strcpy(mininos[3].nombre,"Bolita");
mininos[3].fec.dia=5;
mininos[3].fec.mes=3;
mininos[3].fec.anyo=2017;
tam=4;
}


void MuestraGato(TGatos mininos)
{
		int i=0;
		
		while(mininos[i].nombre[0]!='\0')
	{
			cout<<mininos[i].nombre<<endl;
			i++;
	}
}

void ComprobarVacunas(TGatos mininos,TFecha actual)
{
	int i = 0;
	cout<<"Hay que vacunar a : \n";
	
	while(mininos[i].nombre[0]!='\0')
	{
		
		if(actual.dia<=mininos[i].fec.dia && actual.mes<=mininos[i].fec.mes && actual.anyo>mininos[i].fec.anyo)
		{
			cout<<mininos[i].nombre<<endl;
		}else if(actual.anyo > mininos[i].fec.anyo+1)
			cout<<mininos[i].nombre<<endl;
		i++;
	}
	
}
