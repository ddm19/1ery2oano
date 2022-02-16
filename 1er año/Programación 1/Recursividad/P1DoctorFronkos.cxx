#include <iostream>
using namespace std;

int CuentaCrifras(int num);
void Intercambio (int num1 , int num2,int &resultado);

int main()
{
	int num1,num2,resultado=0;
	bool valido=true;
	
	cin>>num1>>num2;
	
	if(CuentaCrifras(num1)!=CuentaCrifras(num2))
		valido=false;
		
	if(num1<=0 || num2<=0)
		valido=false;
	
	if(valido==true)
		Intercambio(num1,num2,resultado);
	else
		cout<<"ERROR";
		
	
	
	return 0;
}

int CuentaCrifras(int num)
{
	int h=num;
	int i=0;
	while(h!=0)
	{
		
		h=h/10;
		i++;
		
	}
	
	return i;
	
}
void Intercambio (int num1, int num2,int &resultado)
{
	

	
	if(num1/10!=0)
	{
		cout<<"caca"<<endl;
		
		Intercambio(num1/10,num2/10,resultado);
	}
	else
		cout<<resultado;
}
