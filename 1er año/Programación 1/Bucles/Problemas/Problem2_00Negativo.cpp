#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int num,result=0;
	
	cin>>num;

	do
	{			
		result=0;						//reinicia result
		while(num!=0)					//suma las cifras del número almacenado en num
		{	
			result=result+num%10;
			num=num/10;
	
		}
		
		num=result;		//el nuevo número a sumar es la suma de las cifras anteriores		
		
	}while(result>=10 || result<=-10);	//Mientras no sea un número de 1 cifra
	
	cout<<result;	

	return 0;
}

