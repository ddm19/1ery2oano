#include <iostream>

int main(int argc, char **argv)
{
	int num,h=0;
	
	cout<<"Introduzca un número entero : ";cin>>num;
	
	while(num<0)
	{
		h++;
		cout<<"Introduzca un número entero : ";cin>>num;
		
		
	
	}
	if(h==0)
		cout<<"No has introducido ninún número Negativo";
	else
		cout<<"Has introducido "<<h" números negativos";

	
	return 0;
}

