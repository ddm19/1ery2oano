#include <iostream>
#include <fstream>
using namespace std;

struct BinChatbot{
	
float threshold;
char similarity[3];
unsigned numIntents;

};

struct BinIntent{
char name[15];
unsigned numExamples;
char response[1000];
};


int main()
{
	ifstream fichero("archivobinario.bin",ios::binary);
	BinChatbot cat1;
	BinIntent int1;
	
	if(fichero.is_open())
	{
		fichero.read((char*)&cat1,sizeof(BinChatbot));
		cout<<cat1.threshold<<" "<<cat1.similarity<<" "<<cat1.numIntents<<endl;
		for(unsigned i = 0; i<cat1.numIntents;i++)
		{
			fichero.read((char*)&int1,sizeof(BinIntent));
			cout<<int1.name<<" "<<int1.numExamples<<" "<<int1.response<<endl;
		}
	}
	
	else
		cout<<"error";
	
	

	
	return 0;
}

