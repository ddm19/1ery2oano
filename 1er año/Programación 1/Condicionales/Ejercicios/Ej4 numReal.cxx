#include <iostream>
using namespace std;

int main()
{
	float num;
	
	cout<<"Introduce un número real : ";cin>>num;
	
	if(num>0 || num<-20)
	{
		cout<<"El número es adecuado";
	}
	else
	{
		cout<<"INCORRECTO";
	}
	
	
	return 0;
}

