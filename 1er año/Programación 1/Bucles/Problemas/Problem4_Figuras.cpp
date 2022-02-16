#include <iostream>

using namespace std;

void TrianguloUp(int tamano)
{
	
	for(int i = 0; i<tamano ; i++)
	{
	
		for(int k = tamano; k>i ; k--)
		{
		
			cout<<" ";
			
		}
		for(int k = 1 ; k<=i*2+1 ; k++)
		{
		
			cout<<".";
		}
		cout<<endl;
	}	
	
}
void TrianguloDown(int tamano)
{
	for(int i = tamano; i>0 ; i--)
	{
	
		for(int k = tamano; k>=i ; k--)
		{
		
			cout<<" ";
			
		}
		for(int k = 1 ; k<=i*2-1 ; k++)
		{
		
			cout<<".";
		}
		cout<<endl;
	}	



}

void Rombo(int tamano)
{
	
	for(int i = 0; i<tamano-1 ; i++)
	{
	
		for(int k = tamano; k>i ; k--)
		{
		
			cout<<" ";
			
		}
		for(int k = 1 ; k<=i*2+1 ; k++)
		{
		
			cout<<".";
		}
		cout<<endl;
	}	

	TrianguloDown(tamano);	
	
}

void Paralelogramo(int tamano)
{
	
	for(int i = 0; i<tamano ; i++)
	{
		for(int k = tamano ; k>=i ; k--)
		{
		
			cout<<" ";
			
		}
		for(int k = 1 ; k<=tamano ; k++)
		{
		
			cout<<".";
		}
		cout<<endl;
	}



}


int main()
{
	int tamano,opcion;
	bool salir=false;
	
	while(salir==false)
	{
		cout<<" \nMenu\n 1.Dibujar Triangulo \n 2.Dibujar Rombo \n 3.Dibujar Paralelepipedo \n 4.Salir \n Selecciona Figura y Tamaño : ";
		cout<<"\n Opción ";cin>>opcion;
		cout<<" Tamaño ";cin>>tamano;
	
		while(opcion<1 || opcion>4)
		{
				cout<<"ERROR \n Vuelve a introducir la opción ";cin>>opcion;
		}
	
		switch (opcion)					//MENÚ
		{
			case 1:
				TrianguloUp(tamano);
				break;
			case 2:
				Rombo(tamano);
				break;
			case 3:
				Paralelogramo(tamano);
				break;
			case 4:
				salir=true;
				break;
		
	
		}
		
	}
	
	return 0;
}

