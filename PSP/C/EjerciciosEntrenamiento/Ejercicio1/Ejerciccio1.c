/*Crea un proceso que cree un proceso hijo, el envíe 3 números enteros aleatorios a través de un pipe. 
El proceso hijo los ordenará y los escribirá en el fichero salida.txt.*/

#include <sys/types.h>
#include <stdlib.h> //Para poder poner EXIT_FAILURE
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> //Para incluir wait(NULL)


#define READ 0
#define WRITE 1
#define POSICIONES_ARRAY 3

int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main () {
    pid_t proceso_hijo;
    int tuberia[2];
    
    if(pipe(tuberia) == -1){
        perror("No ha sido posible crear la tuberia.");
        return(EXIT_FAILURE);
    }

    proceso_hijo = fork();

    if(proceso_hijo == -1){
        perror("No ha sido posible crear el fork");
        return(EXIT_FAILURE);
    }

    if(proceso_hijo == 0){
        int numR1, numR2, numR3;
        close(tuberia[WRITE]);
        read(tuberia[READ], &numR1, sizeof(numR1));
        read(tuberia[READ], &numR2, sizeof(numR2));
        read(tuberia[READ], &numR3, sizeof(numR3));
        close(tuberia[READ]);

        int numeros [2];
        numeros[0] = numR1;
        numeros[1] = numR2;
        numeros[2] = numR3;
        int mayor = 0, medio = 0, menor = 0;

        /*for(int i = 0; i < POSICIONES_ARRAY; i++){
            if(numeros[i] > mayor){
                mayor = numeros[i];
            }
            if(numeros[i] < mayor){
                medio = numeros[i];
            }
            if(numeros[i] < medio){
                menor = numeros[i];
            }
        }*/
        qsort(numeros, POSICIONES_ARRAY,sizeof(int), comparar);

        for(int i = 0; i < POSICIONES_ARRAY; i++){
            printf("Numeros ordenados.\n%d: %d\n", i + 1, numeros[i]);
        }
        //Los escribo en un fichero
        FILE* archivo = fopen("numsOrdenados.txt", "w");
        if(archivo == NULL){
            return 1;
        }

        for(int i = 0; i < POSICIONES_ARRAY; i++){
            fprintf(archivo, "Numeros ordenados.\n%d %d\n", i + 1, numeros[i]);
        }
        
        fclose(archivo);
        printf("El proceso hijo ha terminado su trabajo.");

        exit(EXIT_SUCCESS);
    }else{
        int num1, num2, num3;
        printf("Escribe el primer numero a enviar: ");
        scanf("%d", &num1);
        printf("Escribe el segundo numero: ");
        scanf("%d", &num2);
        printf("Escribe el tercer numero: ");
        scanf("%d", &num3);

        close(tuberia[READ]);
        write(tuberia[WRITE], &num1, sizeof(num1));
        write(tuberia[WRITE], &num2, sizeof(num2));
        write(tuberia[WRITE], &num3, sizeof(num3)); 
        close(tuberia[WRITE]);

        //Esperar a que el hijo termine
        wait(NULL);
        printf("Proceso padre terminó.\n");
    }

    return 0;
}