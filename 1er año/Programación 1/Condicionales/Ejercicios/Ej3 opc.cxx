#include <iostream>
using namespace std;

int main()
{
	int opc;
	
	cout<<" OPCIONES\n1. Reducido \n2. Mediano \n3. Grande\n";
	
	cout<<"Introduce la opción elegida: ";cin>>opc;
	
	if(opc>3 || opc<1)
	{
		cout<<"\nError,La opción introducida no está en la lista";
		
	}
	else
	{
		cout<<"Has seleccionado el tamaño ";
	}
	
	
		if(opc==1)
		{
			cout<<"Reducido";
	
		}
		else if(opc==2)
		{
			cout<<"Mediano";
	
		}
		else if(opc==3)
		{
			cout<<"Grande";
		
		}
	
	
	return 0;
}

