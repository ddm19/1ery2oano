#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <math.h> //-lm

int main(int argc, char *argv[]){

    int fd, tuberia[2]; 
    int nHijos=atoi(argv[2]), totalArchivos;
    char buff[nHijos], archivo[50];
    float nFichero;

    // ESTO LO HAGO PARA SABER EL NÚMERO DE HIJOS
    struct stat sb;
    stat(argv[1], &sb);
    nFichero=sb.st_size;  //Tamaño del fichero origen
    totalArchivos=ceil(nFichero/nHijos);// archivosTotal será el numero de hijos


    pipe(tuberia);
    for(int i=0;i<totalArchivos;i++){
	    if(fork() > 0){
		if(i==0){
			fd = open(argv[1], O_RDONLY);
		}
		read(fd, buff, nHijos);     			 //read (archivo, buffer nbytes)
		write(tuberia[1], buff, nHijos);   		 //write (archivo, buffer, nbytes)
		if(i==totalArchivos-1){
			close(fd);
		}
	    }
	    else{
		sprintf(archivo,"%s.h0%d",argv[1],i);
		fd = creat(archivo, 0666); //0666 tipo de permisos

		read(tuberia[0], buff, nHijos); //leo de la tubería y escribo en el archivo creado por el hijo
		write(fd, buff, nHijos); 
		close(tuberia[0]);
		exit(0);
                close(fd);
	    }
    }
}
