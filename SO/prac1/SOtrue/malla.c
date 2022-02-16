
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char *argv[]){
	pid_t pid;
	pid_t pid2;
 
	for(int i=0;i<atoi(argv[2]);i++){
		pid=fork(); 
		if(pid){
			printf("Soy el proceso %d\n",getpid());
			sleep(2);
		}
		else{
			printf("soy el hijo %d, mi padre es %d\n",getpid(),getppid());
			sleep(2);
			for(int j=0;j<atoi(argv[1]);j++)
			{
				pid2=fork();
				if(pid2)
				{
					printf("Soy el proceso %d\n",getppid());
					sleep(2);
				}
				else
				{
					printf("Soy el proceso %d\n",getppid());
					sleep(2);
					exit(0);
				}		
			}
			exit(0);
		}
		printf("\n");
	}
	exit(0);
}

