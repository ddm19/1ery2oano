#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	printf("RABO \n");
				pid_t pid2;
				int j;
 
				for(j=1;j<=3;j++)
				{
						pid2=fork(); 
					if(pid2)
					{
						printf("Soy el proceso %d\n",getpid());
						sleep(2);
					}
					else
					{
						printf("soy el hijo %d, mi padre es %d\n",getpid(),getppid());
						sleep(2);
						exit(0);
					}
				}
	
	return 0;
}

