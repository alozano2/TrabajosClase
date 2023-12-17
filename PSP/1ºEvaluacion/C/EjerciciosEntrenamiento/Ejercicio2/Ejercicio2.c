/*Crea un proceso que cree dos procesos hijos, luego generará N (20) números aleatorios. 
Enviará los pares al primer hijo, los impares al segundo. Los hijos escribirán 
por pantalla "Soy el hijo 1|2, he recibido ". Por cada número que mande el padre.*/

#include <sys/types.h>
#include <stdlib.h> //Para poder poner EXIT_FAILURE
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> //Para incluir wait(NULL)

#define MAX_NUMEROS_ALEATORIOS 19
#define READ 0
#define WRITE 1

int main () {
    pid_t hijo_1, hijo_2;
    int numerosAleatorios [MAX_NUMEROS_ALEATORIOS];
    int fd_hijo1[2];
    int fd_hijo2[2];

    if(pipe(fd_hijo1) == -1){
        perror("No se pudo crear el pipe");
    }

    if(pipe(fd_hijo2) == -1){
        perror("No se pudo crear el pipe");
    }

    hijo_1 = fork();
    
    if(hijo_1 == -1){
        perror("Error al crear el proceso hijo 1.");
        exit(EXIT_FAILURE);
    }
    
    if(hijo_1 == 0){
        close(fd_hijo1[WRITE]);
        close(fd_hijo2[READ]);
        close(fd_hijo2[WRITE]);
        int numerosPares;
        
        while (read(fd_hijo1[READ], &numerosPares, sizeof(int)) > 0) {
            printf("Soy el hijo 1, he recibido: %d\n", numerosPares);
        }

        close(fd_hijo1[READ]);
        exit(0);
    }

    hijo_2 = fork();

    if(hijo_2 == -1){
        perror("Error al crear el proceso hijo 2.");
        exit(EXIT_FAILURE);
    }

    if(hijo_2 == 0){
        close(fd_hijo2[WRITE]);
        close(fd_hijo1[WRITE]);
        close(fd_hijo2[READ]);
        int numerosImpares;
        
        while (read(fd_hijo2[READ], &numerosImpares, sizeof(int)) > 0) {
            printf("Soy el hijo 2, he recibido: %d\n", numerosImpares);
        }

        close(fd_hijo2[READ]);
        exit(0);
    }

    if(getpid() != 0){
        srand(time(NULL));
        printf("Los numeros son:\n");

        close(fd_hijo1[READ]);
        close(fd_hijo2[READ]);

        for(int i = 0; i <= MAX_NUMEROS_ALEATORIOS; i++){
            numerosAleatorios[i] = rand() % 100;
            printf("%d.- %d\n", i + 1, numerosAleatorios[i]);

            if(numerosAleatorios[i] % 2 == 0){
                write(fd_hijo1[WRITE], &numerosAleatorios[i], sizeof(int));
            }else{
                write(fd_hijo2[WRITE], &numerosAleatorios[i], sizeof(int));
            }
        }

        close(fd_hijo1[WRITE]);
        close(fd_hijo2[WRITE]);

        printf("El padre ha pasado los numeros.");
        wait(NULL);
        wait(NULL);
    }
    
    return 0;
}

/*HACER EL EJERCICIO HACIENDO QUE LOS HIJOS LE ENVIEN AL PADRE
LA SUMA DE LOS NUMEROS Y EL PADRE LOS IMPRIMA*/