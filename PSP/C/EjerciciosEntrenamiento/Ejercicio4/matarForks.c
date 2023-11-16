#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

#define NUMERO_PARAMETROS 2
#define MAX_PROCESOS 100

void killSignal (int signal){
    printf("Proceso %d eliminado.\n", getpid());
    exit(0);
}

int main (int argc, char *argv[]){
    
    if(argc != NUMERO_PARAMETROS){
        printf("Debes ingresar un entero como parametro.");
        return 1;
    }

    int numero = atoi(argv[1]);
    pid_t hijo[MAX_PROCESOS];

    for(int i = 0; i < numero; i++){
        hijo[i] = fork();

        if(hijo[i] == 0){
            printf("Hijo %d creado correctamente: %d\n",i + 1, getpid());
            signal(SIGUSR1, killSignal);
            while (1) {
                sleep(1); // El proceso hijo espera y no hace nada
            }
        }
    }

    if(hijo > 0){

        for(int i = 0; i < numero; i++){
            kill(hijo[i], SIGUSR1);
        }

        for (int i = 0; i <= numero; i++) {
            wait(NULL);
        }
    }

    return 0;
}

