/*Crea un proceso que sea capaz de gestionar un señal definida por el usuario. 
Luego hará fork y el padre le enviará la señas al hijo. Al gestionar la señal 
el hijo escribirá "Recibido y terminará el proceso."*/

#include <sys/types.h>
#include <stdlib.h> //Para poder poner EXIT_FAILURE
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> //Para incluir wait(NULL)
#include <signal.h> //Para trabajar con señales

void manejadorDeSeñales(int signo){
        printf("Proceso %d eliminado.\n", getpid());
        exit(0);
}

int main (){
    pid_t proceso_hijo;
    proceso_hijo = fork();

    if(proceso_hijo == -1){
        perror("Error al crear el proceso hijo.");
        exit(EXIT_FAILURE);
    }

    if(proceso_hijo == 0){
        printf("Hola soy el proceso hijo numero %d\n", getpid());
        printf("He recibido la señal, adios.\n");
        signal(SIGINT, manejadorDeSeñales);

        while (1) {
            sleep(1); // Mantenemos al proceso hijo activo
        }
    }

    if(proceso_hijo != 0){
        printf("Soy tu padre y te mato\n");
        sleep(2);
        kill(proceso_hijo, SIGINT);
        wait(NULL);
    }

    return 0;
}