/*Crea un proceso que cree dos procesos hijos, luego generará N (20) números aleatorios. 
Enviará los pares al primer hijo, los impares al segundo. Los hijos escribirán por pantalla 
"Soy el hijo 1|2, he recibido ". Por cada número que mande el padre.*/

#include <sys/types.h>
#include <stdlib.h> //Para poder poner EXIT_FAILURE
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> //Para incluir wait(NULL)
#include <signal.h> //Para trabajar con señales

#define NUMERO_PARAMETROS 2
#define MAX_PROCESOS 100

void mandarSignal(int signo) {
    printf("Proceso %d eliminado.\n", getpid());
    exit(0);
}

int main (int argc, char *argv[]) {

    if(argc != NUMERO_PARAMETROS){
        printf("No has ingresado el parametro que indica el numero de hijos ");
        printf("que hay que crear:\nNumero parametros pasados:%d\n",argc);
        return 1;
    }

    int numeroProcesos = atoi(argv[1]);
    pid_t proceso_hijo;

    for(int i = 0; i <= numeroProcesos; i++){
        proceso_hijo = fork();
        if(proceso_hijo == 0){
            printf("Proceso hijo, he sido creado con numero %d.\n",getpid());
            printf("Me salgo para que otro hermano sea creado.\n");
            signal(SIGINT, mandarSignal);

            while (1) {
                sleep(1); // El proceso hijo espera y no hace nada
            }
        } 
    }

    if(proceso_hijo > 0){
        for(int i = 1; i <= numeroProcesos; i++){
            kill(proceso_hijo, SIGINT);
        }

        for(int i = 1; i <= numeroProcesos; i++){
            wait(NULL);
        }
    }

    return 0;
}