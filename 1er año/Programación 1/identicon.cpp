#include <iostream>
using namespace std;

void LeeUsuario(int &num,int &tamano);
int SumaDigitos(int num);
void DibujaIdenticon(int tamano,char especial,int num);
char RestoCaracter(int i, int k , int num);

int main()
{
	int tamano,num,sumadig;
	char especial;
	
	LeeUsuario(num,tamano);
	sumadig=SumaDigitos(num);
	
	 if(sumadig%2==0)		//Establezco el carácter según si la suma de sus dígitos es par o impar
		especial='=';
	else
		especial='%';
		
	DibujaIdenticon(tamano,especial,num);

	return 0;
}

void DibujaIdenticon (int tamano,char especial,int num)
{
for(int i=1 ; i<=tamano ; i++)
	{
		for(int k = 1 ; k<=tamano ; k++)	
		{
				if((i==1 && k==1) || (i==tamano && k==tamano) || (i==1 && k==tamano) || (i==tamano && k==1))
					cout<<"+";
				else if(i==1 || i==tamano)
					cout<<"-";
				else if(k==1 || k==tamano)
					cout<<"|";
				else if (i==2 && k==2)
					cout<<especial;	
				else 
					cout<<RestoCaracter(i-2,k-2,num);
		}
		cout<<endl;
	}	
}

int SumaDigitos (int num)
{
	int suma=0;
	
	while(num!=0)
	{
		suma+=num%10;
		num=num/10;

	}
	return suma;
}

void LeeUsuario(int &num,int &tamano)
{
	cout<<"Introduce un número positivo: ";cin>>num;
	cout<<"Tamaño del identicon: ";cin>>tamano;
}

char RestoCaracter(int i ,int k , int num)
{
	int suma=i+k+1;
	int resto=num%suma;
	char caracter;
	
	if(resto==0)
		caracter='.';
	else if (resto==1)
		caracter='*';
	else
		caracter='o';
		
	return caracter;
	
}
