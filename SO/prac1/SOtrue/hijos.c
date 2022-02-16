#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h> //wait()
#include <string.h> //strcmp
#include <unistd.h>
#include <signal.h>
#include <sys/shm.h>


int main(int argc, char * argv[]) {
  int i, x, y, pid;

  // Punteros para el uso de 'shmat'.
  int * puntero1, * puntero2, shm1, shm2;

  int hijos = 0;

  if (argc != 3) 
  {
    printf("ERROR! Parámetros Incorrectos.\n");
  } 
  else
   {
    printf("\n");

    x = atoi(argv[1]);
    y = atoi(argv[2]);

    if (x <= 0 || y <= 0) 
    {
      printf("ERROR! los valores de x o y son incorrectos\n");
    } 
    else 
    {
      // IPC_PRIVATE => memoria solo accesible por hijos.
      // Obtención de un segmento de memoria compartida con su ID
      shm1 = shmget(IPC_PRIVATE, sizeof(int) * (x + 1), IPC_CREAT | 0666);
      shm2 = shmget(IPC_PRIVATE, sizeof(int) * y, IPC_CREAT | 0666);

      //Vinculación de la dirección de memoria compartida
      puntero1 = (int * ) shmat(shm1, 0, 0);
      puntero2 = (int * ) shmat(shm2, 0, 0);
      // Accedo a los punteros como vectores

      //PID del primer padre
      puntero1[0] = getpid();

      
      for (i = 1; i <= x; i++) 
      {
        pid = fork(); 
        if (pid != 0)
          break; // El padre deja de hacer fork()
        else 
        {
          printf("Soy el subhijo %d mis padres son: ", getpid());

          // Imprimo los procesos padre
          for (hijos = 0; hijos < i; hijos++) 
          {
            printf("%d", puntero1[hijos]);

            if (hijos != i - 1) 
              printf(", ");
          }
          printf("\n");

          // Guardo los PID de los hijos
          puntero1[i] = getpid();
        }
      }

      if (i <= x) 
      {
        
        wait(NULL);

        if (i == 1)
         {
          printf("Soy el superpadre %d mis hijos son ", getpid());

          // Imprimo los IDs de la primera fila
          for (i = 1; i <= x; i++)
           {
            printf("%d", puntero1[i]);
            printf(", ");
          }

          // Imprimo los IDs de la primera columna
          for (i = 1; i <= y; i++)
           {
            printf("%d", puntero2[i - 1]);
            if (i < y)
              printf(", ");
          }

          printf("\n");
        }
      } 
      else
       {

        for (i = 1; i <= y; i++) {

          pid = fork();

          if (pid == 0) // El Hijo no tiene más hijos
          { 
            puntero2[i - 1] = getpid();
            sleep(20);
            break;
          }
        }

        if (i == y + 1) //El padre espera
        { 
          for (i = 1; i <= y; i++)
            wait(NULL);
        }
      }
    }
  }

  return 0;
}

// gcc -g -o hijos hijos.c
// ./hijos 3 5 &
// pstree -c | grep hijos
