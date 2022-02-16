#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 #include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
 #include <strings.h>

#define PORT 9999
#define MAXDATA 100000

int main(int argc, char *argv[]){
	
	
	int conector = socket(AF_INET,SOCK_STREAM,0);	
	int nbytes=20;
	char buff[MAXDATA];
	char buff2[MAXDATA];
	struct sockaddr_in cliente;
	struct in_addr;
	
	if(argc>=3)
	{
		if(conector==-1)
		{
			printf("Error de conexión\n");	
			exit(-1);
		}
		
		cliente.sin_addr.s_addr = inet_addr(argv[1]); 
		cliente.sin_family = AF_INET;
		cliente.sin_port = htons(PORT);
		bzero(&(cliente.sin_zero),8);
		
		if(connect(conector, (struct sockaddr *)&cliente, sizeof(struct sockaddr))==-1)	// si no conseguimos conectar con el servidor (Connect devuelve un -1)
		{
			printf("Error al conectar al servidor\n");
			exit(-1);
		}
		
		
		if ((nbytes=recv(conector,buff,MAXDATA,0)) == -1)	// Si no conseguimos recibir mensaje del socket (recv devuelve -1)
		{  
		  printf("Error al recibir mensaje del socket (recv) \n");
		  exit(-1);
	    }
		
			
		buff[nbytes]='\0';
		printf("Servidor: %s\n", buff);	// Imprimo el estado del Servidor
		
		
		send(conector, argv[2], 100,0);	//Transmitimos el mensaje/comando del cliente al socket servidor
		
		if ((nbytes=recv(conector,buff2,sizeof(buff2),0)) == -1)
		{  
			printf("Error en recv() \n");
			exit(-1);
		}

		
		buff2[nbytes]='\0';
		printf("%s\n", buff2);
		
		close(conector);	
	}	

}
