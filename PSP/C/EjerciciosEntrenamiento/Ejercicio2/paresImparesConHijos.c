/*Crea un proceso que cree dos procesos hijos, luego generará N (20) números aleatorios. 
Enviará los pares al primer hijo, los impares al segundo. Los hijos escribirán por
pantalla "Soy el hijo 1|2, he recibido ". Por cada número que mande el padre.*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define NUMEROS_ALEATORIOS 19

int main () {
    int mypipe1[2], mypipe2[2];
    pid_t proceso_hijo1;
    pid_t proceso_hijo2;
    int numerosAleatorios[19];

    //Compruebo que las tuberias se han creado correctamente
    if (pipe(mypipe1) == -1 || pipe(mypipe2) == -1) {
        perror("Error al crear las tuberías.");
        exit(EXIT_FAILURE);
    }

    //Creo el proceso hijo uno y trbajo con el 
    proceso_hijo1 = fork();

    if (proceso_hijo1 == -1) {
        perror("Error al crear el proceso hijo 1.");
        exit(EXIT_FAILURE);
    }

    if (proceso_hijo1 == 0) {
        close(mypipe1[1]);
        int numeroRecibido;

        while (read(mypipe1[0], &numeroRecibido, sizeof(int)) > 0) {
            printf("Soy el hijo 1, he recibido: %d\n", numeroRecibido);
        }

        close(mypipe1[0]);
        exit(0);
    }

    //Creo el proceso hijo dos
    proceso_hijo2 = fork();

    if (proceso_hijo2 == -1) {
        perror("Error al crear el proceso hijo 2.");
        exit(EXIT_FAILURE);
    }

    if (proceso_hijo2 == 0) {
        close(mypipe2[1]);
        int numeroRecibido;
        while (read(mypipe2[0], &numeroRecibido, sizeof(int)) > 0) {
            printf("Soy el hijo 2, he recibido: %d\n", numeroRecibido);
        }
        close(mypipe2[0]);
        exit(0);
    }

    //Creo los numeros aleatorios (PROCESO PADRE)
    srand(time(NULL));
    close(mypipe1[0]);
    close(mypipe2[0]);

    for(int i = 0; i <= NUMEROS_ALEATORIOS; i++){
        numerosAleatorios[i] = rand() % 100;

        if(numerosAleatorios[i] % 2 == 0){
            write(mypipe1[1], &numerosAleatorios[i], sizeof(int));
        }else{
            write(mypipe2[1], &numerosAleatorios[i], sizeof(int));
        }
    }

    close(mypipe1[1]);
    close(mypipe2[1]);

    wait(NULL);
    wait(NULL);

    return 0;
}