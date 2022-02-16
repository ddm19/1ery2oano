#include <iostream>
using namespace std;

int main()
{
	int conchas=0,mejillones=0,entrada;
	
	cout<<"Indica el número de mollas por concha (finaliza introduciendo \"-1\")\n";
	
	while(entrada!=-1)
	{
		cin>>entrada;
		conchas++;
		mejillones+=entrada;
		
		
		
	}
	conchas--;
	mejillones++;
	
	if(mejillones>conchas)
	{
		cout<<"SUERTE";
	}
	else if (conchas> mejillones)
	{
		cout<<"TIMO";
	}
	else
	{
		cout<<"JUSTO";
	}	
	
	
	return 0;
}

