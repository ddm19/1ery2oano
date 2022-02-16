#include <iostream>
using namespace std;

const unsigned kMATSIZE=5;

void deleteChar(char str[],char c);
unsigned factorial(unsigned n);
bool checkPassword(const char passwd[]);
int calculator (const int numbers[],unsigned size,const char operators[]);
unsigned buildNumber(const unsigned numbers[],unsigned size);
bool friends(unsigned x, unsigned y);
int sumNeighbors(int m[][kMATSIZE],int row,int column);
void printX(int n);


void deleteChar(char str[],char c)
{
	int i = 0,k;
	while(str[i]!='\0' )
	{
		if(str[i]==c)
		{	
			k=i;
			while(str[k]!='\0' || str[k+1]!='\0')
				{
					str[k]=str[k+1];
					k++;
				}
			i--;
		}
		i++;
	}
	
	
}

unsigned factorial(unsigned n)
{
	int suma=1;
	
	for(unsigned i = 1; i<=n ; i++)
	{
		suma=suma*i;
			
	}
	
	return suma;
}

bool checkPassword(const char passwd[])
{
	int i = 0,tam;
	bool valida=true,min=false,max=false,nume=false;
	
	while(passwd[i]!='\0')
	{		
		i++;
	}
	tam=i;
	
	if(tam!=16)
	{
		if(tam<8 || tam>12)
			valida=false;
		else
		{
			i=0;
			while(passwd[i]!='\0')
			{
				if(islower(passwd[i]))
					min=true;
				if(isupper(passwd[i]))
					max=true;
				if(isdigit(passwd[i]))
					nume=true;
				i++;
			}	
			if(!(min && max && nume))
			valida=false;
		}
	}
	else
	{
		i=0;
		while(passwd[i]!='\0')
		{	
			if(!isdigit(passwd[i]))
				valida=false;
			i++;
		}
	}
	return valida;	
}

int calculator (const int numbers[],unsigned size,const char operators[])
{
	int resultado=numbers[0];
	unsigned i=0;
	
	while(i<(size-1) && operators[i]!='\0')
	{
		switch (operators[i]){
			case '+':
				resultado=resultado+numbers[i+1];
				break;
			case '/':
				resultado=resultado/numbers[i+1];
				break;
			case '*':
				resultado=resultado*numbers[i+1];
				break;
			case '-':
				resultado=resultado-numbers[i+1];
				break;
			default:
				i=900;
				break;
		}
		i++;
	}

	return resultado;
}

unsigned buildNumber(const unsigned numbers[],unsigned size){
	
	unsigned concatenado=0;
	
	for(unsigned i = 0 ; i<size ; i++)
		{
			concatenado=concatenado*10;
			concatenado=concatenado+numbers[i];
			
		}
	
	
	return concatenado;

}

bool friends(unsigned x, unsigned y)
{
	unsigned div1=0,div2=0;
	
	
	for(unsigned i = 0 ;i<x ; i++)
	{
		if(x%i==0)
		{
			div1++;
			
		}
	}
	for(unsigned i = 0 ; i<y ; i++)
	{
		if(y%i==0)
		{
			div2++;
			
		}
	}
	cout<<div1<<endl<<div2;

	return true;
	
}

int sumNeighbors(int m[][kMATSIZE],int row,int column)
{
	int suma = 0;
	
	if(row > 5 or column > 5)
	{
		return -1;
	}
	else
	{
		
		for(int i  = -1 ; i<=1 ; i++)
		{
			if(!(row-1 > 5 or column+i > 5 or row-1 < 0 or column+i < 0))
				suma = suma+m[row-1][column+i];
		}
		for(int i  = -1 ; i<=1 ; i++)
		{
			if(!(row+1 > 5 or column+i > 5 or row+1 < 0 or column+i < 0))
				suma = suma+m[row+1][column+i];
		}
		for(int i  = -1 ; i<=1 ; i=i+2)
		{
			if(!(row > 5 or column+i > 5 or row < 0 or column+i < 0))
				suma = suma+m[row][column+i];
		}


		
		return suma;
	}
	
	
}

void printX(int n)
{
	if(n%2!=0){
		for(int i = 0 ; i<n ; i++)
		{
			for(int k = 0 ; k<n ; k++)
			{
				if(i==k or i+k==n-1)
					cout<<"X";
				else
					cout<<" ";
			}
		cout<<endl;
		}
	}
	else
		cout<<"ERROR";
}
	

