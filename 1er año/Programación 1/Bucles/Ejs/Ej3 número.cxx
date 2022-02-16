#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char **argv)
{
	int num,result=0,n,i = 1;
	
	cin>>num;
	
	while(n!=0)
	{
		 
	
		n=fmod(num,pow(10,i))/pow(10,i-1);
		
		
		result=result+n;
		
		i++;
	}
		cout<<result;
	
	
	return 0;
}

