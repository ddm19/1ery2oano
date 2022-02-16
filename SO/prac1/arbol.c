#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
void alarma()
{
	system("pstree -p | grep arbol");
}

int main (int argc,char* argv[])
{
	pid_t pidPadre,pidA,pidB,pidX,pidY,pidZ;	//Creo los PID de todos los procesos para posteriormente almacenarlos
	
	int tiempo = atoi(argv[1]);
	
	pidPadre = getpid();
	printf("\nSoy el procesor ejec mi pid es %d \n",pidPadre);
	signal(SIGALRM,alarma); 					//comando signal para usar alarm
	
	pid_t pid = fork();
	
	if(pid == 0)	// Proceso A
	{
		pidA = getpid();
		wait(0);
		printf("Soy el proceso A: mi pid es %d,mi padre es %d\n",pidA,pidPadre);
		
		//Proceso B
		pid = fork();
	
		if(pid == 0)
		{
			pidB = getpid();
			alarm(tiempo);
			printf("Soy el proceso B: mi pid es %d,mi padre es %d\n",pidB,pidA);
			pause();
			pid = fork();
			if(pid == 0)	//Proceso X
			{
				pidX = getpid();
				alarm(tiempo);
				printf("Soy el proceso X: mi pid es %d,mi padre es %d\n",pidX,pidB);
				pause();
				
			}
			
			pid = fork();
			if(pid == 0)	//Proceso Y
			{
				pidY = getpid();
				alarm(tiempo);
				printf("Soy el proceso Y: mi pid es %d,mi padre es %d\n",pidY,pidB);
				pause();
			}
			
			pid = fork();
			if(pid == 0)	//Proceso Z
			{
				pidZ = getpid();
				alarm(tiempo);
				printf("Soy el proceso Z: mi pid es %d,mi padre es %d\n",pidZ,pidB);	//Falta añadir el control de procesos para que Z controle el orden de muerte de los procesos
				
			}
			
			
		}
		
		
	}
	
	return 0;
}
