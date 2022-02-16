#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int num1,num2,mult,pide=-1;
	float puntos=0,intento=2;
	int aciertos=0;
	
	srand((unsigned)time(NULL));
	
		
		
	for(int i = 0 ; i<5 ; i++)		//Repite para 5 números
	{		
		num1=rand()%10;				//
		num2=rand()%10;				//Genera números aleatorios 0-9
		mult=num1*num2;				//
		
		intento=2;					//Reinicia el número de intentos
		
		while(pide!=mult && intento>=1)	// Multiplicar 1 número
		{

			cout<<num1<<"*"<<num2<<"= ";cin>>pide;

	
			if(pide==mult)			//si acierta
			{
				cout<<"ACIERTO!\n";
				aciertos++;
			}
			else if (pide<mult && intento==2)	
			{
				cout<<"Error!: LA SOLUCIÓN ES MAYOR\n";
				intento--;
			}
			else if (intento == 2)
			{
				cout<<"Error!: LA SOLUCIÓN ES MENOR\n";
				intento--;
			}
			else 						//Fallo completo
			{
				cout<<"Error\n";
				intento--;
			}

		}
	
		puntos=puntos+intento/2;	// Suma los puntos anteriores + esta multiplicación
	}
	
	cout<<"PUNTUACIÓN : ";cout<<puntos;
	

	

	

	return 0;
}

