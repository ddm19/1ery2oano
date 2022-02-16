#include <iostream>


using namespace std;


#include "LlistaNoms.h"

LlistaNoms::LlistaNoms()
{

}

bool LlistaNoms::exist(string nom)
{
	bool exist=false;
	
	for(unsigned i = 0; tranferibles.size() ; i++)
	{
		if(tranferibles[i]==nom)
			exist=true;
	}
		
	return exist;
}
void LlistaNoms::add(string nom)
{	
	tranferibles.push_back(nom);	
}
void LlistaNoms::remove(string nom)
{	
	for(unsigned i = 0; i<tranferibles.size() ; i++)
		if(tranferibles[i]==nom)
			tranferibles.erase(tranferibles.begin()+i);
}
