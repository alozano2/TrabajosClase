/*Crea un programa que cree un hijo y le mande a través de un pipe un carácter y dos números. 
El carácter representa una operación matemática: suma o resta. 
El proceso hijo devolverá en su estado el resultado de la operación.*/

#include <sys/types.h>
#include <stdlib.h> //Para poder poner EXIT_FAILURE
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> //Para incluir wait(NULL)
#include <signal.h> //Para trabajar con señales

#define READ 0
#define WRITE 1

int main () {
    int tuberia[2];
    pid_t proceso_hijo;

    if(pipe(tuberia) == -1){
        perror("Error al crear la tuberia, vuelva a intentarlo.");
    }

    proceso_hijo = fork();

    if(proceso_hijo == -1){
        perror("Error al crear al proceso hijo.");
    }

    if(proceso_hijo == 0){
        int numRecib1, numRecib2;
        char charRecib;
        close(tuberia[WRITE]);
        read(tuberia[READ], &numRecib1, sizeof(numRecib1));
        read(tuberia[READ], &numRecib2, sizeof(numRecib2));
        read(tuberia[READ], &charRecib, sizeof(charRecib));

        int resultado;
        if(charRecib == '+'){
            resultado = numRecib1 + numRecib2;
        }

        if(charRecib == '-'){
            if(numRecib1 < numRecib2){
                resultado = numRecib2 - numRecib1;
            }else{
                resultado = numRecib1 - numRecib2;
            }
        }

        if(charRecib == '*'){
            resultado = numRecib1 * numRecib2;
        }

        printf("%d %c %d = %d\n",numRecib1, charRecib, numRecib2, resultado);
        printf("El proceso hijo terminó\n");
    }

    if(proceso_hijo != 0){
        int num1, num2;
        char operacion;
        close(tuberia[READ]);

        printf("Escribe el primer numero a enviar\n");
        scanf("%d", &num1);
        printf("Escribe el segundo numero a enviar\n");
        scanf("%d", &num2);
        // Limpia el buffer antes de leer el carácter
        while ((getchar()) != '\n'); // Descarta los caracteres restantes en el buffer, incluyendo el '\n'

        printf("Escribe el tipo de operacion a realizar\n");
        scanf(" %c",&operacion);

        if(operacion != '+' && operacion != '-' && operacion != '*'){
            printf("El caracter introducido no es valido. Debe ser '+', '-' o '*'");
            exit(EXIT_FAILURE);
        }
        
        write(tuberia[WRITE], &num1, sizeof(num1));
        write(tuberia[WRITE], &num2, sizeof(num2));
        write(tuberia[WRITE], &operacion, sizeof(operacion));
        close(tuberia[WRITE]);

        wait(NULL);
        printf("Proceso padre terminó.\n");
    }
}