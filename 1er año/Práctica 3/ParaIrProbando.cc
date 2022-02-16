#include <iostream>
#include "Util.h"
#include "Intent.h"
#include "Example.h"
#include "Chatbot.h"
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
	vector <string> tokens;
	string texto;
		getline(cin,texto);
	try{
		Chatbot megabot;
		
		megabot.
	}
	catch(Error e)
	{
		Util::error(e);
	}
/*
	try 						// Constructor de un Intent con excepción si vacío
	{
		
		Intent prueba(texto);
		cout<<prueba.getName()<<endl;
		cout<<"Nexamples "<<prueba.getNumExamples()<<endl;
		
		//cin.get();
		getline(cin,texto);
		
		prueba.addResponse(texto);
		cout<<prueba.getResponse();
		
	while(texto!="p")
	{
		getline(cin,texto);
		if(texto!="p")
		{	
			try // Constructor Example con Excepción si vacío + Intent.AddExample() con excepción si MaxExamples
			{
		
				Example caca(texto);
				tokens=caca.getTokens();
				prueba.addExample(caca);
		
			}
			catch(Error e)
			{
				Util::error(e);
			}
		}
	}

	cout<<prueba;
	}
	catch(Error e)
	{
		Util::error(e);
	}
	
*/
	
	return 0;
}

