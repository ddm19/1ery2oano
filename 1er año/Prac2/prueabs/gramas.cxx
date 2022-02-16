#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
	vector <string> gramas;
	bool esta;
	string palabra = "HolaHola";
	char grama[3];
	
	unsigned k=0;
	
	do
	{	
		for(unsigned i = 0 ; i<3 ; i++)
		{
			grama[i]=palabra[k+i];
		}
		
		esta=false;
		
		for(unsigned i = 0 ; i<gramas.size() ; i++)
		{
			if(strcmp(gramas[i].c_str(),grama)==0)
				esta=true;
		}
		if(!esta)
			gramas.push_back(grama);
		
		k++;
	}while(palabra[k+2]!='\0');
	
	for(unsigned i = 0 ; i<gramas.size() ; i++)
	{
		cout<<gramas[i];
		cout<<endl;
	}
	
	return 0;
}

