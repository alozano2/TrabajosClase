#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

void signalMandada (int signo){
        printf("Señal recibida\n");
        exit(0);
}

int main() {
    pid_t hijo;
    hijo = fork();

    if(hijo == 0){
        printf("Hijo creado: %d \n",getpid());
        signal(SIGUSR1, signalMandada);

         while (1) {
            sleep(1); // El proceso hijo espera y no hace nada
        }
    }

    if(hijo > 0){
        sleep(1);
        kill(hijo, SIGUSR1);
        wait(NULL);
    }

    return 0;
}