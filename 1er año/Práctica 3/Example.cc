#include "Example.h"
#include "Util.h"
#include "Intent.h"
#include <cstring>

int Example::nextid=1;
string t_example="Example ";
string t_token="Tokens ";

Example::Example(string t)
{
	id=nextid;
	text=t;
	tokens=Util::extractTokens(text);
	if(tokens.size()==0)
		throw(ERR_EMPTY);	//Excepción si cadena vacía
	else
		nextid++;
		
		
}

Example::~Example()
{
	//cout<<"DESTRUIDO";
	
}

int Example::getId() const { return id; }
string Example::getText() const{ return text; }
vector <string> Example::getTokens() const{	return tokens; }
void Example::resetNextId()
{
	nextid=1;
}

unsigned Example::Comparador(vector <string> tokens1,vector <string> tokens2) const
{
	unsigned comun=0;
	
		for(unsigned i= 0; i<tokens1.size();i++)
		{
			
		
			for(unsigned k = 0 ; k<tokens2.size();k++)		
			{
					
			
				if(tokens1[i]==tokens2[k])
				{ 
					//cout<<tokens1[i]<<"/"<<tokens2[k]<<endl;
					comun++;
				}
			}
		
		}
	
	return comun;
}

float Example::jaccardSimilarity(string text) const
{
	unsigned comun;
	float jaccard;
	
	vector <string> tokenstexto=Util::extractTokens(text);
	vector <string> tokensexample = getTokens();
	
		
	comun=Comparador(tokenstexto,tokensexample);
	
	jaccard = comun/float(tokensexample.size());
	
	return jaccard;
}

bool Example::AntiDuplicados(vector <string> palabras, string adicionar) const
{
	bool esta=false;
	
	for(unsigned i=0 ; i<palabras.size() ; i++)
	{
		if(strcmp(adicionar.c_str(),palabras[i].c_str())==0)
			esta=true;
	}
	
	return esta;
	
}

vector <string> Example::DiviGramas(string palabra) const	//divide en trigramas una palabra y quita duplicados
{
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
	
	return gramas;
}

float Example::ngramSimilarity(string text) const
{
	unsigned comun;
	float resultado;
	vector <string> gramas1,gramas2,tempgramas;
	vector <string> tokenspregunta=Util::extractTokens(text);	
	vector <string> tokensrespuesta=Util::extractTokens(getText());	
	
	for(unsigned i = 0 ; i<tokenspregunta.size() ; i++)		//Creo el Vector de trigramas con la pregunta
	{
		tempgramas=DiviGramas(tokenspregunta[i]);
		
		for(unsigned k=0;k<tempgramas.size();k++)
		
			if(!AntiDuplicados(gramas1,tempgramas[k]))															//Código repetido a eliminar si es posible
				gramas1.push_back(tempgramas[k]);
	
	}

		
	for(unsigned i = 0 ; i<tokensrespuesta.size() ; i++)		//Creo el Vector de trigramas con la respuesta
	{
		tempgramas=DiviGramas(tokensrespuesta[i]);
		
		for(unsigned k=0;k<tempgramas.size();k++)
		
			if(!AntiDuplicados(gramas2,tempgramas[k]))
				gramas2.push_back(tempgramas[k]);
	
	}
	
	comun=Comparador(gramas1,gramas2);
	
	
	
	resultado = comun/float(gramas2.size());
	
	return resultado;
	
}

ostream& operator<<(ostream &os,const Example &example)
{
	vector <string> tokens=example.getTokens();
	cout<<t_example<<example.getId()<<" : "<<example.getText()<<endl;
	cout<<t_token<<example.getId()<<" : ";
	for(unsigned i = 0 ; i<tokens.size() ; i++)
	{
		cout<<"<"<<tokens[i]<<"> ";
	}
	cout<<endl;
		return os;
}
