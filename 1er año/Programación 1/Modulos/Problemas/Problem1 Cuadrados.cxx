#include <iostream>
using namespace std;

void LeePar(char &c1,char &c2, int &n);  //Lectura de Datos

void Dibuja(char c1,char c2,int n,int &espacio , int &caracteres); //Dibujo del Cuadrado


int main()
{
	int n,caracteres=0,espacio=0;
	char c1,c2;
	
	LeePar(c1,c2,n);
	Dibuja(c1,c2,n,espacio,caracteres);	
	
	cout<<"El número de caracteres dibujado es "<<caracteres<<endl;
	cout<<"El tamaño del espacio interior "<<espacio<<endl;
	return 0;

}
void LeePar(char &c1,char &c2, int &n)
{	
	cout<<"Introduce un carácter: ";cin>>c1;
	
	cout<<"Introduce otro carácter (R/V): ";cin>>c2;
	do
	{
		if(n<4 || n>20)
			cout<<n<<" no es válido\n";
			
		cout<<"Introduce un número (entre 4 y 20): ";cin>>n;
		
	}while(n<4 || n>20);
}
void Dibuja(char c1,char c2,int n,int &espacio , int &caracteres)
{
	if(c2=='V')
	{
		for(int i = 0 ; i<n ; i++)			//Cuadrado Vacío
		{
			for(int k = 0 ; k<n ; k++)
			{
				if(i==0 || i==n-1 || k==0 || k == n-1) 	// Si el carácter a dibujar está en la primera o última linea o columna
				{
					cout<<c1;
					caracteres++;
				}
				else
				{
					cout<<" ";
					espacio++;
				}
			}
			cout<<endl;
		}
	}
	else 								//Cuadrado relleno
	{
		for(int i = 0 ; i<n ; i++)				
		{
			for(int k = 0 ; k<n ; k++)
			{
				cout<<c1;
				caracteres++;
			}
			cout<<endl;
		}
	}
}
	

