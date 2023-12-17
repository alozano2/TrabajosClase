/*Actualizacion del ejercicio 2, haciendo que LOS HIJOS LE ENVIEN AL PADRE
LA SUMA DE LOS NUMEROS Y EL PADRE LOS IMPRIMA*/

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
    int fd_padre1[2];
    int fd_padre2[2];

    //COMPROBAMOS QUE LOS PIPES SE CREAN CORRECTAMENTE

    if(pipe(fd_hijo1) == -1){
        perror("No se pudo crear el pipe");
    }

    if(pipe(fd_hijo2) == -1){
        perror("No se pudo crear el pipe");
    }

    if(pipe(fd_padre1) == -1){
        perror("No se pudo crear el pipe");
    }

    if(pipe(fd_padre2) == -1){
        perror("No se pudo crear el pipe");
    }

    //TRABAJAMOS CON EL PRIMER HIJO
    hijo_1 = fork();
    
    if(hijo_1 == -1){
        perror("Error al crear el proceso hijo 1.");
        exit(EXIT_FAILURE);
    }
    
    if(hijo_1 == 0){
        close(fd_hijo1[WRITE]);
        close(fd_hijo2[READ]);
        close(fd_hijo2[WRITE]);

        close(fd_padre1[READ]);
        close(fd_padre2[WRITE]);
        close(fd_padre2[READ]);
        int numerosPares;
        int suma = 0;
        
        while (read(fd_hijo1[READ], &numerosPares, sizeof(int)) > 0) {
            printf("Soy el hijo 1(%d), he recibido: %d\n", getpid(), numerosPares);
            suma += numerosPares + numerosPares;
        }

        write(fd_padre1[WRITE], &suma, sizeof(suma));
        close(fd_hijo1[READ]);
        close(fd_padre1[WRITE]);
        exit(0);
    }

    //TRABAJAMOS CON EL SEGUNDO HIJO
    hijo_2 = fork();

    if(hijo_2 == -1){
        perror("Error al crear el proceso hijo 2.");
        exit(EXIT_FAILURE);
    }

    if(hijo_2 == 0){
        close(fd_hijo2[WRITE]);
        close(fd_hijo1[WRITE]);
        close(fd_hijo1[READ]);

        close(fd_padre1[READ]);
        close(fd_padre1[WRITE]);
        close(fd_padre2[READ]);
        int numerosImpares;
        int suma = 0;
        
        while (read(fd_hijo2[READ], &numerosImpares, sizeof(int)) > 0) {
            printf("Soy el hijo 2(%d), he recibido: %d\n",getpid(), numerosImpares);
            suma += numerosImpares + numerosImpares;
        }

        write(fd_padre2[WRITE], &suma, sizeof(suma));
        close(fd_padre2[WRITE]);
        close(fd_hijo2[READ]);
        exit(0);
    }

    //TRABAJAMOS CON EL PADRE
    if(getpid() != 0){
        int sumaImpar, sumaPar;

        srand(time(NULL));
        printf("Los numeros son:\n");

        close(fd_hijo1[READ]);
        close(fd_hijo2[READ]);
        close(fd_padre1[WRITE]);
        close(fd_padre2[WRITE]);

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

        printf("El padre ha pasado los numeros.\n");
        //sleep(10);
        wait(NULL);
        wait(NULL);

        /*Es importante que el padre lea esta info despues de esperar a los hijos
        ya que asi te aseguras de que los procesos hijos hayan terminado antes de 
        intentar leer de los pipes.*/
        while(read(fd_padre1[READ], &sumaPar, sizeof(int)) > 0){
            printf("La suma de todos los numeros pares es: %d\n",sumaPar);
        }

        while(read(fd_padre2[READ], &sumaImpar, sizeof(int)) > 0){
            printf("La suma de todos los numeros impares es: %d\n",sumaImpar);
        }

        close(fd_padre1[READ]);
        close(fd_padre2[READ]);
    }
    
    return 0;
}
