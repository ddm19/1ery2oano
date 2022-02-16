//54207039H Daniel Domenech Moreno
//		g++ -Wall -g converter.o prac2.cc -o prac2 			COMPILAR
//		./prac2					EJECUTAR
//Daniel Domenech Moreno 54207039H
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
string cleanString(string);

enum Error{
  ERR_OPTION,
  ERR_INTENT,
  ERR_EXAMPLE,
  ERR_RESPONSE,
  ERR_FILE,
  ERR_THRESHOLD,
  ERR_SIMILARITY,
  ERR_ARGS
}; 
const int KSIZE=10;
const int KMAXTEXTS=15;
const int KMAXTEXTL=1000;
const string intent="Intent name: ";
const string threshold = "Enter threshold: ";
const string algorithm = "Enter algorithm: ";
const string filename = "Enter filename: ";
const string saveallintents = "Save all intents [Y/N]?: ";
const float coefjaccard=0.25;

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
      break;
    case ERR_FILE:
      cout << "ERROR: cannot open file" << endl;
      break;
    case ERR_THRESHOLD:
      cout << "ERROR: the threshold value must be between 0 and 1" << endl;
      break;
    case ERR_SIMILARITY:
      cout << "ERROR: valid values are \"jc\" (Jaccard) and \"ng\" (n-grams)" << endl;
      break;
    case ERR_ARGS:
      cout << "ERROR: invalid arguments" << endl;
  }
}

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

struct BinIntent{
char name[KMAXTEXTS];
unsigned numExamples;
char response[KMAXTEXTL];
};

struct BinChatbot{
float threshold;
char similarity[3];
unsigned numIntents;
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

string CreaIntents(Chatbot &megabot,string linea)
{
	bool separador,repe;
	unsigned i;
	Intent tempIntent;
	
			tempIntent.name="";
			tempIntent.response="";
			i=0	;
			separador=true;
			i++;
			while(i<linea.length() && separador==true)
			{
				if(linea[i]!='#')
					tempIntent.name = tempIntent.name + linea[i];
				else
				separador=false;
				

				
				i++;
			}
			while(i<linea.length())
			{
				tempIntent.response = tempIntent.response+linea[i];
				i++;
			}
			
			CuentaIntents(megabot,tempIntent.name,repe);
			
			if(!repe)
			{
				cout<<endl<<"SI"<<endl;
				megabot.intents.push_back(tempIntent);
			}
			else
				error(ERR_INTENT);
			
		return tempIntent.name;
		/*else
		{
			tempIntent.examples="";
			i=0;
			while(i<linea.length())						//Falta algún método para añadir los examples una vez tenga los intents
			{
				tempIntent.example = examples+linea[i];
				i++;
			}
			cout<<"Example: "<<tempIntent.examples<<endl;
		}*/
	
}

string Donlimpio (string palabra)
{
	
	string tempo="";
	
	
	
for(unsigned i = 0; i<=palabra.length(); i++)
{
	
	
	
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

float Jaccard(Example tempExample,Chatbot megabot)
{
	float jaccard=0,tempo;
	float nIntent=-1;
	
	for(float i = 0; i<megabot.intents.size();i++)
	{
		for(float h = 0; h<megabot.intents[i].examples.size();h++)
		{
			
			tempo=float(Comparador(megabot.intents[i].examples[h],tempExample))/float(megabot.intents[i].examples[h].tokens.size());
			if(tempo>jaccard)
			{
				
				jaccard=tempo;
				if(jaccard>coefjaccard)
					nIntent=i;
				
			}
			
		}	
	}
	return nIntent;
}
void showMainMenu(){
  cout << "1- Train" << endl
       << "2- Test" << endl
       << "3- Report" << endl
       << "4- Configure"<<endl
       << "5- Import Data"<<endl	
       << "6- Export data"<<endl
	   << "7- Load chatbot"<<endl
	   << "8- Save chatbot"<<endl
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
	cout<<intent;
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

void CreaExample(Chatbot &megabot,string palabra,string tempo,string nombre)
{
		bool repe=false;
		unsigned ntokens=0,pos=CuentaIntents(megabot,tempo,repe);
		string tokensuma="";
		Example tempExample;
		tempExample.text=nombre;
				
		for(unsigned i = 0; i<palabra.length();i++)	// suma carácteres hasta formar una palabra (encontrar espacios)
		{	
					
				if(palabra[i]!=' ')
					tokensuma=tokensuma+palabra[i];
					
				if((palabra[i]==' ' && palabra[i+1]!=' ') || (palabra[i]!=' ' && palabra[i+1]=='\0')){	//ya funciona meter los tokens de 1 en 1	
				tokensuma=cleanString(tokensuma);				//quito eñes y cosas que molestan en los tokens (mayus . _ ?...)			
				tokensuma=Donlimpio(tokensuma);
				if(tokensuma.length()>=1)
				{
					ntokens++;
					tempExample.tokens.push_back(tokensuma);		
					tokensuma="";	
				}
			}
				
				
				
		}
		if(ntokens>=1)
		{
			tempExample.id=megabot.nextId;		
			megabot.nextId++;
			
			
			megabot.intents[pos].examples.push_back(tempExample);
		}
	
}

void deleteIntent(Chatbot &megabot){
	string tempo;
	cout<<intent;
	getline(cin,tempo);
	char confirmar;
	bool repe=false;
	unsigned posi=CuentaIntents(megabot,tempo,repe);
	if(repe)
	{
		do
		{
			cout<<"Confirm [Y/N]?: ";cin>>confirmar;
		}while(confirmar!='N' && confirmar!='Y' && confirmar!='y' && confirmar!='n');
		if(confirmar=='Y' || confirmar=='y')
			megabot.intents.erase(megabot.intents.begin()+posi);
		}
	else
		error(ERR_INTENT);
	}
	
void addExample(Chatbot &megabot){
	
	string nombreintent,tokensuma="";
	bool repe=false;
	Example tempExample;
	string palabra;
	
	cout<<intent;
	getline(cin,nombreintent);
	CuentaIntents(megabot,nombreintent,repe);
			
	if(!repe)

			error(ERR_INTENT);	
	else{
		
		while(tempExample.text!="q")			//para salir de los examples coloca "q"
		{	
			tokensuma="";	
			tempExample.text="";
			tempExample.tokens.clear();

			
			cout<<"New example: ";
			getline(cin,tempExample.text);
			
			palabra=tempExample.text;
			
			if(palabra!="q" && palabra!="")
			{
				
				CreaExample(megabot,palabra,nombreintent,tempExample.text);		
			
			}
		}
		
	}
}

void deleteExample(Chatbot &megabot){
	
	int idexample;
	bool erroresta=true;


	cout<<"Example id:";
	cin>>idexample;
	
	for(unsigned i = 0; i<megabot.intents.size();i++)
	{
		for(unsigned k = 0; k<megabot.intents[i].examples.size();k++)
		{
			if(idexample==megabot.intents[i].examples[k].id)
			{		
					megabot.intents[i].examples.erase(megabot.intents[i].examples.begin()+k);
					erroresta=false;
			}
		}
	}
	
	if(erroresta==true)
		error(ERR_EXAMPLE);
}

void addResponse(Chatbot &megabot)
{
	string tempo;
	bool repe=false;
	cout<<intent;
	getline(cin,tempo);
	unsigned pos=CuentaIntents(megabot,tempo,repe); 		
	if(!repe)
			error(ERR_INTENT);	
	else
	{
		cout<<"New response: ";
		getline(cin,tempo);
		megabot.intents[pos].response=tempo;
	}
}

void Configure(Chatbot &megabot) 	//DONETES
{
	float thresh;
	char algort[3],jacc[3],ngrams[3];
	
	strcpy(jacc,"jc");
	strcpy(ngrams,"ng");
	
	cout<<threshold; cin>>thresh;
	if(thresh<0 || thresh>1)
		error(ERR_THRESHOLD);
	else
		megabot.threshold=thresh;
	cout<<algorithm; cin>>algort;
	if(strcmp(algort,jacc) && strcmp(algort,ngrams))
		error(ERR_SIMILARITY);
	else
	strcpy(megabot.similarity,algort);
}

void ImportData(Chatbot &megabot)
{
	string fname,linea,nombreintent,textoexample;

	ifstream fimportar;

	
	cout<<filename;
	getline(cin,fname);
	fimportar.open(fname);
	
	if(!fimportar.is_open())
	{
		error(ERR_FILE);
	}
	
	while(getline(fimportar,linea))
	{
		textoexample=linea;
		
		if(linea[0]=='#')
			nombreintent=CreaIntents(megabot,linea);
		else
			CreaExample(megabot,linea,nombreintent,textoexample);
	}
	
	
	fimportar.close();
}

void GuardarIntent(Chatbot &megabot,string nombrefichero,int numintent)
{
	ofstream fichero(nombrefichero);
	
	if(fichero.is_open())
	{
		fichero<<"#"<<megabot.intents[numintent].name<<"#"<<megabot.intents[numintent].response<<endl;
		
	}
	
}

void ExportData(Chatbot &megabot)
{
	char respuesta;
	do
	{
		cout<<saveallintents;cin>>respuesta;
	}while(respuesta!='n' && respuesta!='y' && respuesta!='N' && respuesta!='Y');
	
	GuardarIntent(megabot,"caca",0);
	
	
	
	
	
}

void LoadChatbot(Chatbot &megabot)
{
	
}

void SaveChatbot(Chatbot &megabot)
{
	
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
	
		cout<<">>"<<greetings[position]<<endl;
		
	do
	{
		palabra="";
		tempExample.text="";
		tempExample.tokens.clear();
		cout<<"<< ";
		getline(cin,comando);
	if(comando!="q")
	{
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
			cout<<">> "<<megabot.intents[nIntent].response<<endl;
		else
			error(ERR_RESPONSE);
	}
		
	}while(comando!="q");
}
void report(const Chatbot &megabot){
	string similar;
	float nexamples=0,i;
	cout<<"Similarity: ";
	if(strcmp(megabot.similarity,"jc")==0)
		similar="Jaccard";
	else if(strcmp(megabot.similarity,"ng")==0)
		similar="n-gramas";
	cout<<similar<<endl;
	cout<<"Threshold: ";
	cout<<megabot.threshold<<endl;

	for(i = 0; i<megabot.intents.size();i++)
	{
		
		cout<<"Intent: ";
		cout<<megabot.intents[i].name<<endl; 					//Mostrar los Intents
		cout<<"Response: "<<megabot.intents[i].response<<endl;
		nexamples=nexamples+megabot.intents[i].examples.size();
			
			for(unsigned k=0;k<megabot.intents[i].examples.size();k++)
				{
					
					cout<<"Example "<<megabot.intents[i].examples[k].id<<": ";
					cout<<megabot.intents[i].examples[k].text<<endl; 					//Mostrar los Examples
					cout<<"Tokens "<<megabot.intents[i].examples[k].id<<": ";//<<megabot.intents[i].examples[k].tokens.size();
					for(unsigned h = 0;h<megabot.intents[i].examples[k].tokens.size();h++)
						{
							cout<<"<"<<megabot.intents[i].examples[k].tokens[h]<<"> ";
						}
					
					cout<<endl; 			
				}
			
	}	
	cout<<"Total intents: "<<megabot.intents.size()<<endl;
	cout<<"Total examples: "<<nexamples<<endl;
	if(nexamples!=0 && megabot.intents.size()!=0)
		cout<<"Examples per intent: "<<nexamples/megabot.intents.size()<<endl;
	else
		cout<<"Examples per intent: "<<0<<endl;
	
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
      case '4':
		Configure(megabot);
		break;
	  case '5':
		ImportData(megabot);
		break;
	  case '6':
		ExportData(megabot);
		break;
      case 'q':
        break;
      default:
        error(ERR_OPTION);
        
    }
  }while(option!='q');
    
  return 0;
}
