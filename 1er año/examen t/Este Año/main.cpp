#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

#include "TaulaJugadores.h"
#include "LlistaNoms.h"
#include "Jugadora.h"

void per_no_fer_servir() {
// pre: no fer servir
// pos: conte totes les cadenes que calen en el programa
// pot ser que algunes no es facin servir

    cout << "ENTRA EL NOM DEL FITXER:" << endl;

    cout << "NOM JUGADORA:" << endl;
    cout << "NOM EQUIP:" << endl;
    cout << "DATA NAIXEMENT:" << endl;
    cout << "ALTURA:" << endl;

    cout << "S'HA FET TRANSFERIBLE UNA JUGADORA" << endl;
    cout << "AQUESTA JUGADORA JA ERA TRANSFERIBLE" << endl;
    cout << "LA JUGADORA NO EXISTEIX" << endl;

    cout << "JUGADORA NOVA. VOLS DONAR-LA D'ALTA? (s/n)" << endl;
    cout << "LA JUGADORA S'HA CANVIAT D'EQUIP" << endl;
    cout << "AQUESTA JUGADORA NO ES TRANSFERIBLE" << endl;

    cout << "LA JUGADORA S'HA DONAT DE BAIXA" << endl;

    cout << "S'HA FET UNA PERMUTA" << endl;
    cout << "NO ES POT FER LA PERMUTA" << endl;

    cout << "JUGADORES DE LA LLIGA" << endl;
    cout << "JUGADORES DE L'EQUIP" << endl;
	cout << "NO HI HA JUGADORES TRANSFERIBLES" << endl;
    cout << "JUGADORES TRANSFERIBLES" << endl;


}

void menu() {
//pre:cert; pos:mostra el menu d'opcions
    cout << "MENU:" << endl;
    cout << "1. Transferible" << endl;
    cout << "2. Alta" << endl;
    cout << "3. Baixa" << endl;
    cout << "4. Permuta" << endl;
    cout << "5. Llistat de jugadores de la lliga" << endl;
    cout << "6. Llistat de jugadores d'un equip" << endl;
    cout << "7. Llistat de jugadores transferibles" << endl;
    cout << "9. Menu" << endl;
    cout << "0. Fi" << endl;
}

void llegir_fitxer(TaulaJugadores & taula,ifstream & ficherLec) {
// pre:cert; pos:s'ha carregat un fitxer a la taula
	string s,nom,equip;
	double altura;
	Data data;
	vector <Jugadora> jugadors;
	
	unsigned i=0;
		
		while(getline(ficherLec,s))
		{
			if(i==0)
			{
				nom=s;
			}
			else if (i==1)
			{
				equip=s;
			}
			else if(i==2)
			{
				int dia,m,any;
				char temp[4];
				
				temp[0]=s[0];
				temp[1]=s[1];
				
				dia=stoi(temp);
				
				temp[0]=s[3];
				temp[1]=s[4];
				
				m=stoi(temp);
				
				temp[0]=s[6];
				temp[1]=s[7];
				temp[2]=s[8];
				temp[3]=s[9];
				
				any=stoi(temp);
				Data d(dia,m,any);
				data=d;
				temp[0]='\0';
				temp[1]='\0';
				temp[2]='\0';
				temp[3]='\0';
				
				
				
				
			}
			else if (i==3)
			{
				altura=stod(s);
			}
			i++;
			if(i==4)
			{
				Jugadora temp(nom,equip,data,altura);
				jugadors.push_back(temp);
				i=0;
			}
		}
		//cout<<"Jugadora"<<endl<<nom<<" "<<equip<<" "<<altura<<endl;
	

		TaulaJugadores taulatemp(jugadors);
		
	
}

void es_transferible(const TaulaJugadores & taula, LlistaNoms & transferibles) {
// pre:cert; pos:es posa a transferibles una jugadora entrada per teclat, si és a la taula
	string nome;
	
	 cout << "NOM JUGADORA:" << endl;cin>>nome;
	 
	if(taula.exist(nome))
	{
		if(transferibles.exist(nome))
		{
			transferibles.add(nome);
			cout << "S'HA FET TRANSFERIBLE UNA JUGADORA" << endl;
		}
		else 
			 cout << "AQUESTA JUGADORA JA ERA TRANSFERIBLE" << endl;
	}
	else
	 cout << "LA JUGADORA NO EXISTEIX" << endl;

		
	
}

void fer_alta(TaulaJugadores & taula, LlistaNoms & transferibles) {
// pre:cert; pos:es fa l'alta d'una jugadora nova o d'una de transferible 
	string nomjugadora,nomequip;
	double altura;
	string s;
	char confirm;
	
	 cout << "NOM JUGADORA:" << endl;cin>>nomjugadora;
	 cout << "NOM EQUIP:" << endl;cin>>nomequip;
	 
	 if(!taula.exist(nomjugadora))
	 {
		while(confirm!='s' && confirm!='n')
		{
		 cout << "JUGADORA NOVA. VOLS DONAR-LA D'ALTA? (s/n)" << endl;cin>>confirm;
		}
		if(confirm=='s')
		{
			 cout << "DATA NAIXEMENT:" << endl;getline(cin,s);
			 cout << "ALTURA:" << endl;cin>>altura;
			 
			 int dia,m,any;
				char temp[4];
				
				temp[0]=s[0];
				temp[1]=s[1];
				
				dia=stoi(temp);
				
				temp[0]=s[3];
				temp[1]=s[4];
				
				m=stoi(temp);
				
				temp[0]=s[6];
				temp[1]=s[7];
				temp[2]=s[8];
				temp[3]=s[9];
				
				any=stoi(temp);
				Data d(dia,m,any);
				
			 Jugadora tempjugadora(nomjugadora,nomequip,d,altura);
		}
	 }
	 else 
	 {
		if(transferibles.exist(nomjugadora))
		{
			transferibles.remove(nomjugadora);
			taula.canviequip(nomequip,nomjugadora);
		} 
		
	 }
		
	  
	 
	 
}

void fer_baixa(TaulaJugadores & taula, LlistaNoms & transferibles) {
// pre:cert; pos:es fa la baixa d'una jugadora (si existeix)

}

void fer_permuta(TaulaJugadores & taula, LlistaNoms & transferibles) {
// pre:cert; pos: es fa una pernuta de dues jugadroes, si són transferibles

}

void llistar_lliga(const TaulaJugadores & taula) {
// pre:cert; pos:es mostra el llistat de les jugadores de la lliga

}

void llistar_equip(const TaulaJugadores & taula) {
// pre:cer; pos:es mostra el llistat de les jugadores d'un equip

}

void llista_transferibles(const LlistaNoms & transferibles) {
//pre:cert; pos:es mostres les jugadores trasferibles

}

int main()
{
    TaulaJugadores taula;
    LlistaNoms transferibles;
    string nomficher;
    
    cout << "ENTRA EL NOM DEL FITXER:" << endl;cin>>nomficher;
    
    ifstream ficherLec(nomficher);
    if(ficherLec.is_open())
    {
		llegir_fitxer(taula,ficherLec);
	}

    int opcio;

    menu();
    cout << endl;
    cout << "Opcio:" << endl;
    cin >> opcio;

    while (opcio != 0) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (opcio == 1)
            es_transferible(taula, transferibles);
        else if (opcio == 2)
            fer_alta(taula, transferibles);
        else if (opcio == 3)
            fer_baixa(taula, transferibles);
        else if (opcio == 4)
            fer_permuta(taula, transferibles);
        else if (opcio == 5)
            llistar_lliga(taula);
        else if (opcio == 6)
            llistar_equip(taula);
        else if (opcio == 7)
            llista_transferibles(transferibles);
        else if (opcio == 9)
            menu();
        else
            menu();
        cout << endl;
        cout << "Opcio:" << endl;
        cin >> opcio;
    }

    cout << "FINS AVIAT!" << endl;
    return 0;
}


