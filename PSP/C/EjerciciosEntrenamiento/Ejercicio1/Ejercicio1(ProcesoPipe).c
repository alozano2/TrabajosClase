/*Crea un proceso que cree un proceso hijo, el envíe 3 números enteros 
aleatorios a través de un pipe. El proceso hijo los ordenará y los escribirá 
en el fichero salida.txt.*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define NUMEROS_ENTEROS 3

int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    pid_t proceso_hijo;
    int mypipe[2];
    int numerosAleatorios[NUMEROS_ENTEROS];

    //Abrimos el archivo en modo escritura
    FILE* archivo = fopen("arrayNumeros.txt", "w");
    //Comprobamos si se pudo abrir
    if(archivo == NULL){
        perror("No se pudo abrir el archivo.");
        return 1;
    }

    // Inicializar la semilla de rand() con el tiempo actual para obtener números aleatorios diferentes en cada ejecución.
    srand(time(NULL));

     // Crear el pipe
    if (pipe(mypipe) == -1) {
        perror("Error al crear el pipe.");
        exit(EXIT_FAILURE);
    }

    //CREO EL PROCESO HIJO
    proceso_hijo = fork();

    if(proceso_hijo == -1){
        perror("Error al crear el proceso hijo.");
        exit(EXIT_FAILURE);
    }

    if(proceso_hijo != 0){
        close(mypipe[0]);

        for(int i = 0; i <= NUMEROS_ENTEROS; i++){
        numerosAleatorios[i] = rand() % 100;
        }
        printf("El padre ya ha creado los numeros\n");
        write(mypipe[1],numerosAleatorios,sizeof(numerosAleatorios));
        close(mypipe[1]);
        wait(NULL);
        exit(0);
    }else{
        close(mypipe[1]);
        read(mypipe[0], numerosAleatorios, sizeof(numerosAleatorios));
        close(mypipe[0]);

        /*La funcion qsort ordena los numeros. Es necesario crear una funcion 
        anterior (comparar) para pasarsela y decirle como quiero ordenar los numeros.*/
        qsort(numerosAleatorios,NUMEROS_ENTEROS,sizeof(int), comparar);

        for(int i = 0; i <= NUMEROS_ENTEROS; i++){
            if(i == 0){
                fprintf(archivo,"El hijo los muestra:\n");
                fprintf(archivo, "%d.- %d\n", i + 1, numerosAleatorios[i]);
            }else if(i == 3){
                fprintf(archivo, "El hijo ha terminado.\n");
            }else{
                fprintf(archivo, "%d: %d\n", i + 1, numerosAleatorios[i]);
            }
        }
        
        fclose(archivo);
        exit(0);
    }
    return 0;
}