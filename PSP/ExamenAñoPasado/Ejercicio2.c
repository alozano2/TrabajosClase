/*Crea un programa que cree dos pipes, después haga fork. 
El padre enviará 3 números aleatorios al proceso hijo a través de uno de los pipes.
El proceso hijo los ordenará y los escribirá en un pipe de vuelta al padre ordenados.
El padre muestra la información y espera a que finalice el hijo.*/

#include <sys/types.h>
#include <stdlib.h> //Para poder poner EXIT_FAILURE
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> //Para incluir wait(NULL)

#define READ 0
#define WRITE 1
#define MAX_NUMEROS_ALEATORIOS 3

int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/*Esta seria para ordenar los numeros en orden de mayor a menor:
int comparar(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}
*/

int main(){
    int pipe1[2];
    int pipe2[2];
    pid_t proceso_hijo;
    int numerosAleatorios [MAX_NUMEROS_ALEATORIOS];

    if(pipe(pipe1) == -1){
        perror("Error al crear la tuberia 1.");
    }

    if(pipe(pipe2) == -1){
        perror("Error al crear la tuberia 2");
    }

    proceso_hijo = fork();

    if(proceso_hijo == 0){
        int numR1, numR2, numR3;
        int numeros[MAX_NUMEROS_ALEATORIOS];
        close(pipe1[WRITE]);
        close(pipe2[READ]);

        //Leo los numeros que ha mandado el padre
        read(pipe1[READ], &numR1, sizeof(numR1));
        read(pipe1[READ], &numR2, sizeof(numR2));
        read(pipe1[READ], &numR3, sizeof(numR3));

        //Los meto en el array de numeros para ordenarlos.
        numeros[0] = numR1;
        numeros[1] = numR2;
        numeros[2] = numR3;

        //Los ordeno
        qsort(numeros, MAX_NUMEROS_ALEATORIOS,sizeof(int), comparar);

        //Una vez ordenados se los envio de vuelta al padre.
        for(int i = 0; i < MAX_NUMEROS_ALEATORIOS; i++){
            write(pipe2[WRITE], &numeros[i], sizeof(int));
        }
    }

    if(proceso_hijo != 0){
        srand(time(NULL));
        close(pipe1[READ]);
        close(pipe2[WRITE]);

        for(int i = 0; i < MAX_NUMEROS_ALEATORIOS; i++){
            numerosAleatorios[i] = rand() % 100;
            printf("Los numeros aleatorios son: %d\n",numerosAleatorios[i]);
            write(pipe1[WRITE], &numerosAleatorios[i], sizeof(int));
        }

        close(pipe1[WRITE]);
        wait(NULL);

        int numerosOrdenados[MAX_NUMEROS_ALEATORIOS];
        for(int i = 0; i < MAX_NUMEROS_ALEATORIOS; i++){
            read(pipe2[READ], &numerosOrdenados[i], sizeof(int));
            printf("Soy el padre. Los numeros ordenador son: %d\n", numerosOrdenados[i]);
        }
        
        wait(NULL);
    }

    return 0;
}