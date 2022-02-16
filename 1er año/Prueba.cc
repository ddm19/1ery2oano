#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	string palabra="La";
	
vector <string> gramas;
	
	
	char grama[3];		
	
	unsigned k=0;
		
	do
	{	
		for(unsigned i = 0 ; i<3 && i<palabra.length() ; i++)
		{
			grama[i]=palabra[k+i];
			
		}	
			gramas.push_back(grama);
		
		k++;
		
	}while(k+2<palabra.length());
	
	
for(unsigned i = 0 ;i<gramas.size() ; i++)

	cout<<gramas[i]<<endl;
}
