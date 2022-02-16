#include<iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <string.h>

#include <fstream>
#include <sstream>

using namespace std;

struct Proceso{
    string nombre;
    unsigned int llegada;
    unsigned int memfalta;
    unsigned int tEjecucion;
    unsigned int contador;
};

struct Procesador{
    vector <Proceso> cola;
    vector <Proceso> ejecutandose;
    unsigned int memoriaTotal;
};

void leerFichero(string nombrei, vector<Proceso> &procesos)	// Leemos el fichero y lo almacenamos en un vector de *procesos*
{
    ifstream file_imported;
    
    file_imported.open(nombrei.c_str(), ios::in);
    
    if(file_imported.is_open()){
        string linea="";      
        
        while(getline(file_imported, linea))
        {
            stringstream ss(linea);
            Proceso proceso;
            
            ss >> proceso.nombre >> proceso.llegada >> proceso.memfalta >> proceso.tEjecucion;
            proceso.contador = proceso.tEjecucion;

            procesos.push_back(proceso);
        }
        
        file_imported.close(); 
    }
    else
    {
        cout<< "No se ha podido encontrar el fichero de entrada" << endl;
    }
}


void reordenarPorLlegada(vector<Proceso> &procesos) //Se reordenan los procesos por tam
{

    for(int i = 1; i < (int)procesos.size(); i++) //Repite hasta ordenado
    {
        for(int j = 0; j < (int)procesos.size() - 1; j++) 
        {  
            if(procesos[j].llegada > procesos[j+1].llegada)
            {
                swap(procesos[j], (procesos[j+1]));    // Traslado los valores grandes al final

            }
        }
    }
}

void AmpliarProcesador(Procesador &procesador, int posi, int memoriaRestante)
{
    Proceso nuevohueco;
    nuevohueco.nombre = "hueco";
    nuevohueco.llegada = 0;
    nuevohueco.contador = 0;
    nuevohueco.tEjecucion = 0;
    nuevohueco.memfalta = memoriaRestante;
    procesador.ejecutandose.push_back(nuevohueco);
	
	for(int i = procesador.ejecutandose.size() - 1 ; i > posi + 1; i--)
	{		
   		swap(procesador.ejecutandose[i], procesador.ejecutandose[i-1]);
	}
}


void eliminarProcesos(vector<Proceso> &ejecutandose)
{

    for(int k = ejecutandose.size() - 1; k >= 0 ; k--)    //se recorre el vector de procesos que se estan ejecutando en sentido contrario

    {
    	
    	if(ejecutandose[k].nombre.compare("hueco") != 0)
        	ejecutandose[k].contador--;
		
        if(ejecutandose[k].contador == 0)		//Si un proceso ha finalizado se convierte en hueco
        {    	
            ejecutandose[k].nombre = "hueco"; 
        }   
    }
}

bool controlaTiempo(vector<Proceso> cola, vector<Proceso> ejecutandose, int memoriaTotal){
    
    bool vivos = false;
    
    if(cola.empty())    //Si la cola de procesos está vacía
    {

        for(int i = 0; i < (int)ejecutandose.size() && vivos == false; i++)	//Si hay procesos vivos
        {
            if(ejecutandose[i].contador != 0)
                vivos = true;
        }
        
        if(ejecutandose[0].nombre.compare("hueco") == 0 && ejecutandose[0].memfalta == (unsigned int) memoriaTotal)  //Siempre como poco vamos a tener un proceso 'hueco' con el contador a 0
        	vivos = false;
    }    
        
    else // si hay procesos en cola
    {
        vivos = true;
    }

    return vivos;
}

void solaparHuecos(vector<Proceso> &ejecutandose)
{
	    
		for(int i = (int) ejecutandose.size() -1; i >= 0; i--)
		{
        	if(i < (int) ejecutandose.size()  - 1 &&  ejecutandose[i].nombre.compare("hueco") == 0 && ejecutandose[i+1].nombre.compare("hueco") == 0)//Compruebo si puede solaparse con otro hueco de al lado
        	{
        		ejecutandose[i].memfalta += ejecutandose[i+1].memfalta;
        		ejecutandose.erase(ejecutandose.begin() + i + 1);	//Se elimina un hueco repetido
			}
		}        
        
}

void colaToProcesador(Procesador &procesador, bool &borrado){
	int hueco = -1;
	        	
    for(int i=0; i < (int) procesador.ejecutandose.size() && borrado == false; i++)	// Si hay Hueco para el primer proceso de la cola
    {

        if(procesador.ejecutandose[i].nombre.compare("hueco") == 0 && procesador.cola[0].memfalta <= procesador.ejecutandose[i].memfalta) //Cabe en un hueco?
        {
            hueco = i;
            int memoriaRestante = procesador.ejecutandose[i].memfalta - procesador.cola[0].memfalta;

            if( memoriaRestante == 0)	//Si no sobra memoria (cabe perfecto) se sustituyen valores
            {
                swap(procesador.ejecutandose[i], procesador.cola[0]);
            }
            
            else 	//Si no, creamos un hueco con la mem que sobra
            {
				AmpliarProcesador(procesador, i, memoriaRestante);
                swap(procesador.ejecutandose[i], procesador.cola[0]);
				solaparHuecos(procesador.ejecutandose);
            }
            
            procesador.cola.erase(procesador.cola.begin());	//Elimino el proceso de la cola

            borrado = true;
        }
    }
    
    if(hueco == -1)
            	borrado = false;
}

void procesosToProcesador(vector<Proceso> &procesos, Procesador &procesador){
	
	int posHueco = -1;
	
    for(int i=0; i < (int) procesador.ejecutandose.size(); i++)	// si hay un hueco bueno para el primer proceso de la cola

    {
    	
        if(procesador.ejecutandose[i].nombre.compare("hueco") == 0 && procesos[0].memfalta <= procesador.ejecutandose[i].memfalta) //Cabe en un hueco?
        {

        	posHueco = i;
            int memoriaRestante = procesador.ejecutandose[i].memfalta - procesos[0].memfalta;
            
            if( memoriaRestante == 0)  //Si no sobra memoria (cabe perfecto) se sustituyen valores
            {
                swap(procesador.ejecutandose[i], procesos[0]);
            }
            
            else 	//Si no, creamos un hueco con la mem que sobra
            {
				AmpliarProcesador(procesador, i, memoriaRestante);
                swap(procesador.ejecutandose[i], procesos[0]);
				solaparHuecos(procesador.ejecutandose);
            }	
        }
    }
    
    if(posHueco == -1) //Si no ha cabido en alguno de los huecos disponibles
    {
        procesador.cola.push_back(procesos[0]);        
	}
	
	procesos.erase(procesos.begin()); 
}

void algPeorHueco(int memoriaTotal, string nombrei, string nombreExportar)
{
	vector<Proceso> procesos;

    leerFichero(nombrei, procesos);

    reordenarPorLlegada(procesos);

    Procesador procesador;
    procesador.memoriaTotal = (unsigned int) memoriaTotal;
    
    Proceso inicio;
    inicio.nombre = "hueco";
    inicio.llegada = 0;
    inicio.contador = 0;
    inicio.tEjecucion = 0;
    inicio.memfalta = memoriaTotal;
    
    procesador.ejecutandose.push_back(inicio);

    
    bool contar = true;
    
    ofstream file_exported;

    file_exported.open(nombreExportar.c_str(), ios::out);

    if(file_exported.is_open()){
    	
		for(int instante = 1; contar == true || !procesos.empty(); instante++)
		{
			
			cout << instante << " ";
       		file_exported << instante << " ";
		   	
		    bool borrado;
		
		    do{
		    	borrado = false;
		    	
		        if( !procesador.cola.empty() && (procesador.cola[0].memfalta > procesador.memoriaTotal)){
		            procesador.cola.erase(procesador.cola.begin());
		            borrado = true;
		        }
				  
		        else if (!procesador.cola.empty()){
					colaToProcesador(procesador, borrado);
		        }
		        	
		    }while(borrado == true);
				
			
		    while(!procesos.empty() && (int)procesos[0].llegada == instante)  //Reubico los procesos originales

		    {		
		    	
		    	int posHueco = -1;
		    	int diferencia = -1;
		    	
			    for(int i=0; i < (int) procesador.ejecutandose.size(); i++){
			    	
			        //Si el primer elemento del vector procesos cabe en un hueco
			        if(procesador.ejecutandose[i].nombre.compare("hueco") == 0 && procesos[0].memfalta <= procesador.ejecutandose[i].memfalta)
			        {
			        	if(unsigned(diferencia) < procesador.ejecutandose[i].memfalta - procesos[0].memfalta || diferencia == -1) 	// La principal diferencia con el algoritmo del mejor hueco es que aquí se busca que la diferencia sea mayor en lugar de menor
			        	{																											// Es decir, se busca el mayor hueco en lugar del menor o más ajustado
				        	posHueco = i;
				        	diferencia = procesador.ejecutandose[i].memfalta - procesos[0].memfalta;	
						}   		
			        }
			    }
			    
			    //Si no cabe en ningun hueco
			    if(posHueco == -1)
			    {
			        procesador.cola.push_back(procesos[0]);        
				}
				else
				{
		            if( diferencia == 0)	//Si no sobra memoria (cabe perfecto) se sustituyen valores
		            {
		                swap(procesador.ejecutandose[posHueco], procesos[0]);
		            }
		            
		            else 	//Si no, creamos un hueco con la mem que sobra
		            {
						AmpliarProcesador(procesador, posHueco, diferencia);
		                swap(procesador.ejecutandose[posHueco], procesos[0]);
						solaparHuecos(procesador.ejecutandose);
		            }	
				}
				
				procesos.erase(procesos.begin()); 			    	
		    }		
			
			int posInicial = 0;
			
		    for(int i = 0; i < (int)procesador.ejecutandose.size(); i++)	//Se imprimen (en fichero y terminal) los procesos
		    {
		    	
		        cout << "[" << posInicial << " " 
		            << procesador.ejecutandose[i].nombre << " " 
		            << procesador.ejecutandose[i].memfalta << "] ";
		            
		        file_exported << "[" << posInicial << " " 
		            		  << procesador.ejecutandose[i].nombre << " " 
		                      << procesador.ejecutandose[i].memfalta << "] ";
		        
		        posInicial += procesador.ejecutandose[i].memfalta;
		    }       
			cout << endl;
			file_exported << endl;
			
			contar = controlaTiempo(procesador.cola, procesador.ejecutandose, memoriaTotal);
		    eliminarProcesos(procesador.ejecutandose);
		    solaparHuecos(procesador.ejecutandose);
		    	

		}

        file_exported.close();
    }
    else
        cout << "Error! No se ha podido crear el fichero de salida " << endl;
    
    
    cout << "Fin de Algoritmo"  << endl;

}

void algMejorHueco(int memoriaTotal, string nombrei, string nombreExportar)
{
	vector<Proceso> procesos;

    leerFichero(nombrei, procesos);

    reordenarPorLlegada(procesos);

    Procesador procesador;
    procesador.memoriaTotal = (unsigned int) memoriaTotal;
    
    Proceso inicio;
    inicio.nombre = "hueco";
    inicio.llegada = 0;
    inicio.contador = 0;
    inicio.tEjecucion = 0;
    inicio.memfalta = memoriaTotal;
    
    procesador.ejecutandose.push_back(inicio);

    
    bool contar = true;
    
    ofstream file_exported;

    file_exported.open(nombreExportar.c_str(), ios::out);

    if(file_exported.is_open()){
    	
		for(int instante = 1; contar == true || !procesos.empty(); instante++)
		{
			
			cout << instante << " ";
       		file_exported << instante << " ";
		   	
		    bool borrado;
		
		    do{
		    	borrado = false;
		    	
		        if( !procesador.cola.empty() && (procesador.cola[0].memfalta > procesador.memoriaTotal)){
		            procesador.cola.erase(procesador.cola.begin());
		            borrado = true;
		        }
				  
		        else if (!procesador.cola.empty()){
					colaToProcesador(procesador, borrado);
		        }
		        	
		    }while(borrado == true);
				
			
		    while(!procesos.empty() && (int)procesos[0].llegada == instante)  //Reubico los procesos originales

		    {		
		    	
		    	int posHueco = -1;
		    	int diferencia = -1;
		    	
			    for(int i=0; i < (int) procesador.ejecutandose.size(); i++){
			    	
			        //Si el primer elemento del vector procesos cabe en un hueco
			        if(procesador.ejecutandose[i].nombre.compare("hueco") == 0 && procesos[0].memfalta <= procesador.ejecutandose[i].memfalta)
			        {
			        	if(unsigned(diferencia) > procesador.ejecutandose[i].memfalta - procesos[0].memfalta || diferencia == -1) 								
			        	{
				        	posHueco = i;
				        	diferencia = procesador.ejecutandose[i].memfalta - procesos[0].memfalta;	
						}   		
			        }
			    }
			    
			    //Si no cabe en ningun hueco
			    if(posHueco == -1)
			    {
			        procesador.cola.push_back(procesos[0]);        
				}
				else
				{
		            if( diferencia == 0)	//Si no sobra memoria (cabe perfecto) se sustituyen valores
		            {
		                swap(procesador.ejecutandose[posHueco], procesos[0]);
		            }
		            
		            else 	//Si no, creamos un hueco con la mem que sobra
		            {
						AmpliarProcesador(procesador, posHueco, diferencia);
		                swap(procesador.ejecutandose[posHueco], procesos[0]);
						solaparHuecos(procesador.ejecutandose);
		            }	
				}
				
				procesos.erase(procesos.begin()); 			    	
		    }		
			
			int posInicial = 0;
			
		    for(int i = 0; i < (int)procesador.ejecutandose.size(); i++)	//Se imprimen (en fichero y terminal) los procesos
		    {
		    	
		        cout << "[" << posInicial << " " 
		            << procesador.ejecutandose[i].nombre << " " 
		            << procesador.ejecutandose[i].memfalta << "] ";
		            
		        file_exported << "[" << posInicial << " " 
		            		  << procesador.ejecutandose[i].nombre << " " 
		                      << procesador.ejecutandose[i].memfalta << "] ";
		        
		        posInicial += procesador.ejecutandose[i].memfalta;
		    }       
			cout << endl;
			file_exported << endl;
			
			contar = controlaTiempo(procesador.cola, procesador.ejecutandose, memoriaTotal);
		    eliminarProcesos(procesador.ejecutandose);
		    solaparHuecos(procesador.ejecutandose);
		    	

		}

        file_exported.close();
    }
    else
        cout << "Error! No se ha podido crear el fichero de salida " << endl;
    
    
    cout << "Fin de Algoritmo"  << endl;

}

int argumentValidation(int argc, char *argv[], string &nombrei, string &nombreExportar, int &memoriaTotal, bool &peorHueco, bool &mejorHueco){
    
    int error = -1;

    for(int i = 1; i < argc && error == -1; i++)    //se recorren los argumentos
    {
        switch(i)					//Primer argumento -> nombre del fichero importado
        {           				//Segundo argumento -> nombre del fichero exportado  
            case 1:					//Tercer argumento -> tamaño de la memoria total
                nombrei = argv[i];  //Cuarto argumento -> selección de algoritmo
            break;

            case 2:
                nombreExportar = argv[i];
            break;
            
            case 3:
                if(atoi(argv[i]) < 0)
                    error = 1;

                memoriaTotal = atoi(argv[i]);
            break;

            case 4:
                //Peor hueco 
                if(strcmp(argv[i], "-p") == 0)
                    peorHueco = true;

                //Mejor hueco 
                else if(strcmp(argv[i], "-m") == 0)
                    mejorHueco = true;

                else
                    error = 2;
            break;
        }
    }
    return error;
}

int main(int argc, char *argv[]){

    string nombrei = "";
    string nombreExportar = "";
    int memoriaTotal = 0;
    bool peorHueco = false, mejorHueco = false;

    if(argc !=5)
		cout << "Error en los argumentos" << endl;
    else{
        int error = argumentValidation(argc, argv, nombrei, nombreExportar, memoriaTotal, peorHueco, mejorHueco);
        if(error == -1)	//Si hay errores se imprimen y se finaliza el programa
        {
            cout << "Fichero de entrada : " << nombrei << endl 
            	 << "Fichero de volcado : " << nombreExportar << endl
                 << "Capacidad máxima del procesador: " << memoriaTotal << endl
				 << "=========================================================" << endl;

            if(peorHueco == true)
            {
                cout << "Algoritmo Seleccionado: Peor hueco" << endl;
                algPeorHueco(memoriaTotal, nombrei, nombreExportar);
            }
            else
            {
                cout << "Algoritmo Seleccionado: Mejor hueco" << endl;
                algMejorHueco(memoriaTotal, nombrei, nombreExportar);
            }
        }

        else if(error == 1)
            cout << "Error! Memoria introducida negativa" << endl;

        else if(error == 2)
            cout << "Error Algoritmo Seleccionado incorrecto" << endl;

        else
            cout << "Error en los argumentos" << endl;
        
    }
    
    return 0;
}
