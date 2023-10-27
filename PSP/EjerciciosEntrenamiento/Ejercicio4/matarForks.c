#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

#define NUMERO_PARAMETROS 2

void killSignal (int signal){
    printf("Proceso eliminado.");
}

int main (int argc, char *argv[]){
    
    if(argc != NUMERO_PARAMETROS){
        printf("Debes ingresar un entero como parametro.");
        return 1;
    }

    int numero = atoi(argv[1]);
    pid_t hijo;

    for(int i = 0; i < numero; i++){
        hijo = fork();

        if(hijo == 0){
            printf("Hijo %d creado correctamente: %d\n",i + 1, getpid());
            while (1) {
                sleep(1); // El proceso hijo espera y no hace nada
            }
        }
    }

    if(hijo > 0){
        for(int i = 0; i < numero; i++){
            signal(killSignal,SIGUSR1);
        }

        for (int i = 0; i < numero; i++) {
            wait(NULL);
        }
    }

    return 0;
}

