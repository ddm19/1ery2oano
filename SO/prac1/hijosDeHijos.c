#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main (){
	int pid;
			
		for(int i=0;i<2;i++)
		{
			pid=fork();
			if(pid==0)
			{
				if(i==1)
				{
					pid_t pid2;
					int j;
 
					for(j=1;j<=3;j++)
					{
						pid2=fork(); 
						if(pid2)
						{
							printf("Soy el proceso %d\n",getpid());
							sleep(1);
						}
						else
						{
							printf("soy el hijo %d, mi padre es %d\n",getpid(),getppid());
							sleep(1);
							exit(0);
						}
		
					}
				}
							
			}
			else
			{
				//printf("PID!=0\n");
				printf("Soy el padre y mi pid es %d\n",getpid());
				wait(NULL);
			}
	}
	sleep(2);
	exit(0);
}
