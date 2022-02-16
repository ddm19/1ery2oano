#include <iostream>
using namespace std;

int main()
{
	int horas,minutos;
	
	cout<<"Introduce la hora : ";cin>>horas>>minutos;
	
	if((horas<0 || horas>23) || (minutos<0 || minutos>59))
	{
		cout<<"ERROR HORA INCORRECTA";
		
	}
	else
	{
		horas=23-horas;
		minutos=60-minutos;
		
		minutos=minutos+(horas*60);
		
		cout<<"Faltan "<<minutos<<" minutos";
	}

	
	return 0;
}

