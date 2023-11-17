/*Crea un proceso que sea capaz de gestionar un señal definida por el usuario. 
Luego hará fork y el padre le enviará la señas al hijo. Al gestionar la señal 
el hijo escribirá "Recibido y terminará el proceso."*/

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