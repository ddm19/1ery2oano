#include "Chatbot.h"
#include <cstring>
#include "Util.h"

const string t_intent="Intent name: ";
const string t_response="New response: ";
const string t_confirm="Confirm [Y/N]?:";
const string t_idexample="Example id:";
const string t_algorithm = "Enter algorithm: ";
const string t_threshold = "Enter threshold: ";
const string t_similarity = "Similarity: ";

Chatbot::Chatbot(float threshold,const char similarity[])
{
	if(threshold < 0 || threshold>1)
		throw(ERR_THRESHOLD);
	else
		this->threshold=threshold;
	if(strcmp(similarity,"jc")!=0 && strcmp(similarity,"ng")!=0)
		throw(ERR_SIMILARITY);
	else
		strcpy(this->similarity,similarity);
	
}

float Chatbot::getThreshold() const { return threshold; }

string Chatbot::getSimilarity() const {	return similarity; }

int Chatbot::searchIntent(string name) const 
{
	int nintent=-1;
	
	
	for(unsigned i = 0; i<intents.size();i++)
	{
		
		if(intents[i]->getName()==name)
		{
			nintent=i;
		}
	}
	
	return nintent;
	
}
bool Chatbot::addIntent(Intent* pIntent)
{
	bool conseguido=false;
	if(searchIntent(pIntent->getName())!=-1)
		throw(ERR_INTENT);
	else
	{
		intents.push_back(pIntent);
		conseguido=true;
	}
		
	return conseguido;
}
bool Chatbot::deleteIntent(string name, bool askConfirm)
{
	bool conseguido=false;
	string tempo=name;
	int nintent=-1;
	char confirmar='y';
	
	if(tempo=="")	//Preguntar Nombre si vacío
	{
		cout<<t_intent;
		getline(cin,tempo);
	}
	nintent=searchIntent(tempo);
	if(nintent==-1)	// Si no existe lanzar error
		throw(ERR_INTENT);
	else 									// Si existe, comenzar borrado
	{
		if(askConfirm)
		{
			do
			{
				cout<<t_confirm;cin>>confirmar;		//Pregunto confirmación
				confirmar=tolower(confirmar);
			}while(confirmar!='y' && confirmar!='n');
		}
		if(confirmar=='y')
		{
			intents.erase(intents.begin()+nintent);
			conseguido=true;
		}
	}
	
	return conseguido;	
}

bool Chatbot::addExample(string name)
{
	bool conseguido=false;
	string tempo=name,texto="";	
	vector <string> tokens;
	int nintent=-1;
	if(tempo=="")	//Preguntar name si vacío
	{
		cout<<t_intent;
		getline(cin,tempo);
	}
	nintent=searchIntent(tempo);
	if(nintent==-1)
		throw(ERR_INTENT);
	else
	{
		while(texto!="p")
		{
			getline(cin,texto);
			if(texto!="p")
			{	
				try // Constructor Example con Excepción si vacío + Intent.AddExample() con excepción si MaxExamples
				{
					Example tempExample(texto);
					tokens=tempExample.getTokens();
					intents[nintent]->addExample(tempExample);
					conseguido=true;
				}
				catch(Error e)
				{
					Util::error(e);
				}
			}
		}
	}
	return conseguido;
	
	
	
}

bool Chatbot::deleteExample(int id)
{
	bool conseguido=false;
	int tempo=id;
	
	if(tempo==0)
	{
		cout<<t_idexample;
		cin>>tempo;
		cin.ignore();
	}
	for(unsigned i = 0 ; i<intents.size();i++)
	{
		try
		{
			intents[i]->deleteExample(tempo);
			conseguido=true;
		}
		catch(Error e)
		{
			
		}
		
	}
	if(!conseguido)
		Util::error(ERR_EXAMPLE);
		
	return conseguido;
}

bool Chatbot::addResponse(string name,string response)
{
	string tempo=name,tempresponse=response;
	bool conseguido=false;
	int nintent;
	
	if(tempo=="")	//Preguntar name si vacío
	{
		cout<<t_intent;
		getline(cin,tempo);
	}
	nintent=searchIntent(tempo);
	if(tempresponse=="")	//Preguntar response si vacío
	{
		cout<<t_response;
		getline(cin,tempresponse);
	}
	
	if(nintent==-1)
		throw(ERR_INTENT);
	else
	{
		intents[nintent]->addResponse(tempresponse);
	}
	
	return conseguido;
	
}

string Chatbot::bestResponse(string query,bool debug) const
{
	float mejor=0,tempo=0;
	string respuesta="",similitudstr=getSimilarity();
	char similarity[3];
	unsigned intentwinner=-1;
	
	strcpy(similarity,similitudstr.c_str());
	
	for(unsigned i = 0; i<intents.size() ; i++)
	{
		tempo=intents[i]->calculateSimilarity(query,similarity);
		if(tempo>mejor)
		{
			mejor=tempo;
			intentwinner=i;
		}
	}
	if(mejor<getThreshold())
		throw(ERR_RESPONSE);
	else
	{
		respuesta=intents[intentwinner]->getResponse();
		if(debug)
			respuesta="("+to_string(mejor)+")"+respuesta;
	}	
	return respuesta;
}

void Chatbot::test(bool debug) const
{	
	string comando="";
	cout<<Util::welcome()<<endl;
	do
	{
		if(comando!="q")
		{
			cout<<"<<";
			getline(cin,comando);
			try
			{
				bestResponse(comando,debug);
			}
			catch(Error e)
			{
				Util::error(e);
			}
		}
	}while(comando!="q");
}

void Chatbot::configure(float threshold,const char similarity[])
{
	float tempthreshold;
	string similitud=similarity;
	char jacc[3],ngrams[3];
	
	strcpy(jacc,"jc");
	strcpy(ngrams,"ng");
	
	if(threshold==-1)
	{
		cout<<t_threshold;
		cin>>tempthreshold;			//si thresh vacío lo pido
		cin.ignore();
	}
	if(string(similarity).length()==0)	//si similarity vacía la pido
	{
		cout<<t_algorithm;
		getline(cin,similitud);
	}
	if(tempthreshold<0 || tempthreshold>1)
		Util::error(ERR_THRESHOLD);			//error si está fuera de los límites
	else
		threshold=tempthreshold;			
		
	if(strcmp(similitud.c_str(),jacc) && strcmp(similitud.c_str(),ngrams))
		Util::error(ERR_SIMILARITY);
	else
		similarity=similitud.c_str();
	
}

ostream& operator <<(ostream& os, const Chatbot chatbot)
{
	
	cout<<t_similarity;
	if(strcmp(megabot.similarity,"jc")==0)
		similar="Jaccard";
	else if(strcmp(megabot.similarity,"ng")==0)
		similar="N-grams";
	cout<<similar<<endl;
	cout<<"Threshold: ";
	cout<<megabot.threshold<<endl;
	
	for(unsigned i = 0; i<chatbot.intents.size() ; i++)
	{	
		cout<<chatbot.intents[i];
	}
	
	return os;
}
