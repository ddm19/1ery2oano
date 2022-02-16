#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int num;
	cout<<"Introduce un número entero :";cin>>num;
	
	if(16%num==0)
	{	
			cout<<"\nEl número "<<num<<" es divisor de 16";
	}
	else
	{
			cout<<"\nEl número "<<num<<" no es divisor de 16";
	}

	
	return 0;
}

