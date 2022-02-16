#include <iostream>
using namespace std;

void Division(int cociente,int &resto,int num1,int num2,int i);

int main()
{
	int cociente=0,resto,num1,num2,i=0;
	
	cin>>num1>>num2;
	
	Division(cociente,resto,num1,num2,i);
	
	return 0;
}

void Division(int cociente,int &resto,int num1,int num2,int i)
{
	
		cociente=i*num2;
		resto=num1-cociente;
		
	if(resto>=num2)
		Division(cociente,resto,num1,num2,i+1);
	else
		cout<<i<<" "<<resto;
}
