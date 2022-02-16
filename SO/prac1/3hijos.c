#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char* argv[]){
  //int x=atoi(argv[1]); //filas
  //int y=atoi(argv[2]); //columnas

  //Padre con 3 hijos
	pid_t pid;
	int i;
 
	for(i=1;i<=3;i++){
		pid=fork(); 
		if(pid){
			printf("Soy el proceso %d\n",getpid());
			sleep(2);
		}
		else{
			printf("soy el hijo %d, mi padre es %d\n",getpid(),getppid());
			sleep(2);
			exit(0);
		}
	}
	sleep(3);
	exit(0);
}	

