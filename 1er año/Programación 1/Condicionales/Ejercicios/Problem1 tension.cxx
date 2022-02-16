#include <iostream>
using namespace std;

int main()
{
	//while(1)
//	{
	int tensalt,tensbaj,aux;
		
	cout<<"Introduce la Tensión Alta y la Tensión Baja respectivamente : ";cin>>tensalt>>tensbaj;
	
	if(tensalt<tensbaj) 		// Intercambio de tensiones si no están en orden
	{
		aux=tensalt;
		tensalt=tensbaj;
		tensbaj=aux;
	}
	
	if(tensalt<90 && tensbaj<60)
	{
		cout<<"HIPOTENSIÓN";
		
		
	}
	else if(tensalt<=140 && tensbaj<=90)
	{
		cout<<"NORMAL";
		
	}
	
	else if(tensalt>180 && tensbaj>110)
	{
		
		cout<<"HIPERTENSIÓN SEVERA-AL HOSPITAL";
	}
	else if(tensalt>160 && tensbaj>100)
	{
		
		cout<<"HIPERTENSIÓN MODERADA";
	}
	else
	{
		cout<<"ERROR DE LECTURA";
		
	}
	
	//cout<<endl;
	//}
	return 0;
}

