#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <strings.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 9999
#define BACKLOG 200
#define MAXLENGTH 850
#define ERROR "Error de servidor"

int main(){
	
	struct sockaddr_in servidor,cliente;
	int servidorfd,clientefd,fd_lector;
	int tuberia[2];
	char comando[MAXLENGTH];
	char hostname_cliente[MAXLENGTH];
	pid_t hijo;

	servidor.sin_family = AF_INET; 
	servidor.sin_port = htons(PORT);
	servidor.sin_addr.s_addr = INADDR_ANY;
	bzero(&(servidor.sin_zero),8);
	
	servidorfd = socket(AF_INET,SOCK_STREAM,0);
	
	if (bind(servidorfd,(struct sockaddr*)&servidor, sizeof (struct sockaddr)) == -1) perror(ERROR);
	
	if(listen(servidorfd,BACKLOG) == -1) perror(ERROR);
	
	
   while(1) //Bucle Inf
   {
		socklen_t sin_size = sizeof(struct sockaddr_in);
		  
		if ((clientefd = accept(servidorfd,(struct sockaddr *)&cliente,&sin_size))==-1) perror(ERROR);
		
		getnameinfo((struct sockaddr *) &cliente, sizeof(cliente), hostname_cliente, sizeof(hostname_cliente), NULL, 0, NI_NAMEREQD);
		printf(">> Conexion de entrada: IP %s (%s)\n",(char*)inet_ntoa(cliente.sin_addr),hostname_cliente); 
		send(clientefd,"Conectado!",sizeof("Conectado!"),0);
		pipe(tuberia);
		fd_lector=recv(clientefd,comando,sizeof(comando),0);
		comando[fd_lector]='\0';
		printf(">> Se ha recibido el comando: %s\n",comando);
		printf(">> Ejecutando el comando %s...\n",comando);

		hijo=fork();
		if(hijo==0)	
		{ 
			close(tuberia[0]);
			dup2(tuberia[1],1);
			dup2(tuberia[1],2);
			close(tuberia[1]);
			execlp(comando,comando,NULL,NULL);
		} 
		else 
		{ 
			char buffer[5000]={0};
			close(tuberia[1]);
			
			while(read(tuberia[0],buffer,sizeof(buffer))!=0); 
			send(clientefd,buffer,sizeof(buffer),0);
		}
	}
}
