#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	char letra;

	cout<<"Introduzca un carácter: ";cin>>letra;


	while(letra!=97 && letra!=101 && letra!=105 && letra!=111 && letra!=117)
	{
		
		cout<<"Introduzca un carácter: ";cin>>letra;

	
	}

	
		
	
	return 0;
}
