#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define READ 0
#define WRITE 1
#define BUFFER 1024

/*Para poder meterle informacion a una cadena, tengo que usar el metodo sprintf, tal y como 
utilizado abajo*/

int main () {
    int fd[2];
    int cd[2];
    float resultado = 0;

    if(pipe(fd) == -1){
        perror("Error al crear el pipe");
        exit(EXIT_FAILURE);
    }

    if(pipe(cd) == -1){
        perror("Error al crear el pipe");
        exit(EXIT_FAILURE);
    }

    pid_t hijo = fork();

    if(hijo == -1){
        perror("Error al crear fork");
        exit(EXIT_FAILURE);
    }

    if(hijo == 0){

        int numeroRecibido1;
        int numeroRecibido2;
        char caracterRecibido[BUFFER];
        char cadena[BUFFER];

        close(fd[WRITE]);
        close(cd[READ]);
        read(fd[READ], &numeroRecibido1, sizeof(numeroRecibido1));
        read(fd[READ], &numeroRecibido2, sizeof(numeroRecibido2));
        read(fd[READ], &caracterRecibido, sizeof(caracterRecibido));
        close(fd[READ]);

        printf("Proceso hijo recibió la cadena: %d %s %d\n", numeroRecibido1, caracterRecibido, numeroRecibido2);

        if(caracterRecibido[0] == '+'){
            resultado = numeroRecibido1 + numeroRecibido2;
            sprintf(cadena, "%d + %d = %.1f\n", numeroRecibido1, numeroRecibido2, resultado);
            write(cd[WRITE], &cadena, sizeof(cadena));
        } else if (caracterRecibido[0] == '-') {
            if (numeroRecibido1 > numeroRecibido2)
            {
                resultado = numeroRecibido1 - numeroRecibido2;
                sprintf(cadena, "%d + %d = %.1f\n", numeroRecibido1, numeroRecibido2, resultado);
                write(cd[WRITE], &cadena, sizeof(cadena));
            }
            else if (numeroRecibido1 < numeroRecibido2)
            {
                resultado = numeroRecibido2 - numeroRecibido1;
                sprintf(cadena, "%d + %d = %.1f\n", numeroRecibido1, numeroRecibido2, resultado);
                write(cd[WRITE], &cadena, sizeof(cadena));
            }
            else
            {
                resultado = numeroRecibido1 - numeroRecibido2;
                sprintf(cadena, "%d + %d = %.1f\n", numeroRecibido1, numeroRecibido2, resultado);
                write(cd[WRITE], &cadena, sizeof(cadena));
            }
        } else if (caracterRecibido[0] == '*') {
            resultado = numeroRecibido1 * numeroRecibido2;
            sprintf(cadena, "%d + %d = %.1f\n", numeroRecibido1, numeroRecibido2, resultado);
            write(cd[WRITE], &cadena, sizeof(cadena));
        } else if (caracterRecibido[0] == '/'){
            if (numeroRecibido2 == 0){
                perror("No se puede dividir entre 0");
            }
            else{
                resultado = numeroRecibido1 / numeroRecibido2;
                sprintf(cadena, "%d + %d = %.1f\n", numeroRecibido1, numeroRecibido2, resultado);
                write(cd[WRITE], &cadena, sizeof(cadena));
            }
        }else{
            perror("El caracter pasado no es un signo matematico.");
            exit(EXIT_FAILURE);
        }
        close(cd[WRITE]);
        exit(resultado);
    }

    if(getpid() != 0){
        int numeroEnviar1;
        int numeroEnviar2;
        char charEnviar[BUFFER];
        char cadenaRecibida[BUFFER];
        

        printf("Introduce el primer numero: \n");
        scanf("%d", &numeroEnviar1);
        printf("Introduce el operando: \n");
        scanf("%s", charEnviar);
        printf("Introduce el segundo numero: \n");
        scanf("%d", &numeroEnviar2);

        close(fd[READ]);
        close(cd[WRITE]);
        write(fd[WRITE], &numeroEnviar1, sizeof(numeroEnviar1));
        write(fd[WRITE], &numeroEnviar2, sizeof(numeroEnviar2));
        write(fd[WRITE], &charEnviar, sizeof(charEnviar));
        close(fd[WRITE]);
        read(cd[READ],&cadenaRecibida, sizeof(cadenaRecibida));
        printf("El padre recibio la cadena: %s\n", cadenaRecibida);

        // Espero a que el hijo termine
        wait(NULL);
        printf("Proceso padre termino\n");
    }

    return 0;
}