#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int segundos;
	
	scanf("%d",&segundos);
	
	
	pid_t pid;
	pid = fork();
	switch (pid)
	{
		case -1:
				printf ("No he podido crear el proceso hijo \n");
				break;
		case 0:
				printf("Soy el hijo,mi PID es %d y mi PPID es %d \n",getpid(),getppid());
				sleep(5);
				break;
		default:
				printf("Soy el padre, mi PID es %d y el PID de mi hijo es %d \n", getpid(),pid);
				sleep(8);
				
	}
	printf("Final de ejecución de %d \n", getpid());
	exit(0);
		
	return 0;
}

