//54207039H Daniel Domenech Moreno
//		g++ -Wall -g converter.o prac1.cc -o prac1 			COMPILAR
//		./prac1					EJECUTAR
//Daniel Domenech Moreno 54207039H
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
string cleanString(string);

enum Error{
  ERR_OPTION,
  ERR_INTENT,
  ERR_EXAMPLE,
  ERR_RESPONSE
}; 

const int KSIZE=10;
const float coefjaccard=0.25;

const string greetings[KSIZE]={
  "Hola, ¿en qué puedo ayudarte?",
  "¿Qué puedo hacer hoy por ti?",
  "Oh, gran prócer de los bits, ¿cuál es tu deseo?",
  "Buenas",
  "¿Qué quieres?",
  "¿Otra vez necesitas ayuda?",
  "¡Hola! Soy Megabot 3000. ¿En qué puedo ayudarte?",
  "Bonito día para ser Megabot 3000",
  "Pregunta sin miedo",
  "Soy todo oídos"
};

struct Example{
int id;
string text;
vector<string> tokens;
};

struct Intent{
string name;
vector<Example> examples;
string response;
};

struct Chatbot{
int nextId;

float threshold;
char similarity[3];
vector<Intent> intents;
};

int CuentaIntents(Chatbot megabot,string tempo,bool &repe)
{

	for(unsigned i = 0; i<megabot.intents.size();i++)
	{
		
		if(megabot.intents[i].name==tempo)
		{
			repe=true;
			return i;
		}
	}	
	return -1;
}

string Donlimpio (string palabra)
{
	
	string tempo="";
	
for(unsigned i = 0; i<=palabra.length(); i++){
	
	if(isupper(palabra[i]))
	{
			palabra[i]=tolower(palabra[i]);
			
	}
	
	if(isalnum(palabra[i]))
	{
			tempo=tempo+palabra[i];
		
	}
	
}
if(tempo[tempo.length()-1]=='s' || tempo[tempo.length()-1]=='s')
{
	
	tempo.erase(tempo.length()-1);
	
}
	return tempo;
}

void QuitaRepes(Example &example)
{
	for(unsigned i= 0; i<example.tokens.size();i++)
	{
		for(unsigned k= i; k<example.tokens.size();k++)
		{
			if(example.tokens[i]==example.tokens[k] && i!=k)
			{
				
				example.tokens.erase(example.tokens.begin()+i);
				k--;
			}
		}
	}
}

int Comparador(Example example1, Example example2)
{
	unsigned comun=0;
	
	QuitaRepes(example1);
	QuitaRepes(example2);
	
	for(unsigned i= 0; i<example1.tokens.size();i++)
	{
		
		for(unsigned k = 0 ; k<example2.tokens.size();k++)
		{
			if(example1.tokens[i]==example2.tokens[k])
			{ 
				comun++;
			}
			

			
		}
		
	}
	return comun;
	
}

void error(Error n){
  switch(n){
    case ERR_OPTION:
      cout << "ERROR: wrong menu option" << endl;
      break;
    case ERR_INTENT:
      cout << "ERROR: wrong intent name" << endl;
      break;
    case ERR_EXAMPLE:
      cout << "ERROR: wrong example id" << endl;
      break;
    case ERR_RESPONSE:
      cout << "Lo siento, pero no tengo respuesta para eso" << endl;
  }
}

int Jaccard(Example tempExample,Chatbot	megabot)
{
	int jaccard=0,tempo;
	int nIntent=-1;
	
	for(unsigned i = 0; i<megabot.intents.size();i++)
	{
		for(unsigned h = 0; h<megabot.intents[i].examples.size();h++)
		{
			
			tempo=Comparador(megabot.intents[i].examples[h],tempExample)/megabot.intents[i].examples[h].tokens.size();
			if(tempo>jaccard)
			{
				
				jaccard=tempo;
				cout<<endl<<jaccard<<endl;
				if(jaccard>coefjaccard)
					nIntent=i;
				else
					error(ERR_INTENT);
				
			}
			
		}	
	}
	return nIntent;
}
void showMainMenu(){
  cout << "1- Train" << endl
       << "2- Test" << endl
       << "3- Report" << endl
       << "q- Quit" << endl
       << "Option: ";
}

void showTrainMenu(){
	
  cout << "1- Add intent" << endl
       << "2- Delete intent" << endl
       << "3- Add example" << endl
       << "4- Delete example" << endl
       << "5- Add response" << endl
       << "b- Back to main menu" << endl
       << "Option: ";
}

void addIntent(Chatbot &megabot){
	string tempo;
	Intent Auxiliar;
	cout<<">> Intent Name: ";
	getline(cin,tempo);
	bool repe=false;
	CuentaIntents(megabot,tempo,repe);
	if(repe)
		error(ERR_INTENT);
	else
	{
		Auxiliar.name=tempo;
		megabot.intents.push_back(Auxiliar);
	}
	}

void deleteIntent(Chatbot &megabot){
	string tempo;
	cout<<">> Intent Name: ";
	getline(cin,tempo);
	char confirmar;
	bool repe=false;
	unsigned posi=CuentaIntents(megabot,tempo,repe);
	if(repe)
	{
		cout<<"Confirm [Y/N]? ";cin>>confirmar;
		if(confirmar=='Y')
			megabot.intents.erase(megabot.intents.begin()+posi);
		}
	else
		error(ERR_INTENT);
	}
	
void addExample(Chatbot &megabot){
	
	string tempo,tokensuma="";
	bool repe=false;
	unsigned ntokens=0;
	Example tempExample;
	cout<<"Intent name: ";
	getline(cin,tempo);
	unsigned pos=CuentaIntents(megabot,tempo,repe); 		
	if(!repe)
			error(ERR_INTENT);	
	else{
		while(tempExample.text!="q")			//para salir de los examples coloca "q"
		{		
			cout<<"New Example: ";
			getline(cin,tempExample.text);
			
			if(tempExample.text!="q" && tempExample.text!="")
			{
				
				for(unsigned i = 0; i<tempExample.text.length();i++)	// suma carácteres hasta formar una palabra (encontrar espacios)
				{	
					
					if(tempExample.text[i]!=' ')
						tokensuma=tokensuma+tempExample.text[i];
					if((tempExample.text[i]==' ' && tempExample.text[i+1]!=' ') || (tempExample.text[i]!=' ' && tempExample.text[i+1]=='\0')){	//ya funciona meter los tokens de 1 en 1	
						tempExample.text=cleanString(tempExample.text);				//quito eñes y cosas que molestan en los tokens (mayus . _ ?...)			
						tokensuma=Donlimpio(tokensuma);
						if(tokensuma.length()>=1)
						{
							ntokens++;
						tempExample.tokens.push_back(tokensuma);		
						tokensuma="";
						}
					}
				
				
				
				}
					
				tempExample.id=megabot.nextId;		//Falta un if comprobando que hay tokens no vacíos
				megabot.nextId++;
				
				megabot.intents[pos].examples.push_back(tempExample);
				tempExample.text="";
				tempExample.tokens.clear();
			}
		}
		
	}
}

void deleteExample(Chatbot &megabot){
int idexample;
char confirmar;


cout<<"Example id:";
cin>>idexample;
	
	for(unsigned i = 0; i<megabot.intents.size();i++)
	{
		for(unsigned k = 0; k<megabot.intents[i].examples.size();k++)
		{
		if(idexample==megabot.intents[i].examples[k].id)
		{
			cout<<"Confirm [Y/N]? ";cin>>confirmar;
			if(confirmar=='Y')
				megabot.intents[i].examples.erase(megabot.intents[i].examples.begin()+idexample);
		}
		else
		error(ERR_EXAMPLE);
		}
	
	}
}

void addResponse(Chatbot &megabot)
{
string tempo;
bool repe=false;
cout<<"Intent name: ";
getline(cin,tempo);
unsigned pos=CuentaIntents(megabot,tempo,repe); 		
	if(!repe)
			error(ERR_INTENT);	
	else
	{
		cout<<"New Response: ";
		getline(cin,tempo);
		megabot.intents[pos].response=tempo;
	}
}

void train(Chatbot &megabot){
	char option;
	do{
		showTrainMenu();
		cin >> option;
		cin.get();
        
		switch (option){ 
		case '1':
			addIntent(megabot);
			break;
		case '2':
			deleteIntent(megabot);
			break;
		case '3':
			addExample(megabot);
			break;
		case '4':
			deleteExample(megabot);
			break;
		case '5':
			addResponse(megabot);
			break;
		case 'b':
			
			break;
		default:
			error(ERR_OPTION);
		
		}
		
	}while(option!='b');
      
}

void test(const Chatbot &megabot)
{
	int position = rand()%KSIZE,nIntent;
	string comando,palabra;
	Example tempExample;
	
	
	cout<<">>"<<greetings[position]<<endl<<"<< ";
	getline(cin,comando);
	
	for(unsigned i = 0; i<comando.length();i++)	// suma carácteres hasta formar una palabra (encontrar espacios)
				{	
					if(comando[i]!=' ')
						palabra=palabra+comando[i];
					if((comando[i]==' ' && comando[i+1]!=' ') || (comando[i]!=' ' && comando[i+1]=='\0')) 
					{	
						palabra=cleanString(palabra);										//quito eñes y cosas que molestan en los tokens (mayus . _ ?...)			
						palabra=Donlimpio(palabra);
						tempExample.tokens.push_back(palabra);
						palabra="";
					}
				}
	nIntent=Jaccard(tempExample,megabot);
	if(nIntent!=-1) 
		cout<<">>"<<megabot.intents[nIntent].response<<endl;
}
void report(const Chatbot &megabot){

cout<<"Intents: \n";

for(unsigned i = 0; i<megabot.intents.size();i++){
	
	cout<<i+1<<" - "<<megabot.intents[i].name<<endl; 					//Mostrar los Intents
	cout<<"Respuesta: "<<megabot.intents[i].response<<endl;
	
	}
cout<<"EXAMPLES: \n";

for(unsigned i = 0; i<megabot.intents.size();i++){
	cout<<"> "<<megabot.intents[i].name<<endl;
	for(unsigned k=0;k<megabot.intents[i].examples.size();k++){
		cout<<k+1<<" >> "<<megabot.intents[i].examples[k].text<<endl; 					//Mostrar los Examples
		for(unsigned h = 0;h<megabot.intents[i].examples[k].tokens.size();h++){
			cout<<">>"<<megabot.intents[i].examples[k].tokens[h]<<"";
			}
			cout<<endl; 			
		}
		cout<<endl;
	}	
cout<<endl;
}

int main(){
  Chatbot megabot;
  megabot.nextId=1;
  megabot.threshold=0.25;
  strcpy(megabot.similarity,"jc");
    
  srand(666);
	
	
  char option;
  do{
    showMainMenu();
    cin >> option;
    cin.get();
        
    switch (option){ 
      case '1':
        train(megabot);
        break;
      case '2':
        test(megabot);
        break;
      case '3':
        report(megabot);
        break;
      case 'q':
        break;
      default:
        error(ERR_OPTION);
        
    }
  }while(option!='q');
    
  return 0;
}
