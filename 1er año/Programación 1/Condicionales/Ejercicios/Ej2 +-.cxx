#include <iostream>
using namespace std;

int main()
{
	char c;
	
	cout<<"Introduce un carácter : ";cin>>c;
	
	if(c=='+')
	{
		cout<<"POSITIVO";
	}
	else if (c=='-')
	{
		cout<<"NEGATIVO";
	}
	else
	{
		cout<<"INCORRECTO";
	}
	
	return 0;
}

