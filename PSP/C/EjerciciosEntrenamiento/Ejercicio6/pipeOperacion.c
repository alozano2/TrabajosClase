/*Crea un programa que cree un hijo y le mande a través de un pipe un carácter y dos números. 
El carácter representa una operación matemática: suma o resta. 
El proceso hijo devolverá en su estado el resultado de la operación.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define READ 0
#define WRITE 1
#define BUFFER 1024
int main()
{
    int fd[2];
    float resultado = 0;

    if (pipe(fd) == -1)
    {
        perror("Error al crear el pipe");
        exit(EXIT_FAILURE);
    }

    pid_t hijo = fork();

    if (hijo == -1)
    {
        perror("Error al crear fork");
        exit(EXIT_FAILURE);
    }

    if (hijo == 0)
    {
        int numeroRecibido1;
        int numeroRecibido2;
        char caracterRecibido[BUFFER];

        close(fd[WRITE]); // Cierro el extremo de escritura ya que el hijo solo va a leer.
        read(fd[READ], &numeroRecibido1, sizeof(numeroRecibido1));
        read(fd[READ], &numeroRecibido2, sizeof(numeroRecibido2));
        read(fd[READ], &caracterRecibido, sizeof(caracterRecibido));

        printf("Proceso hijo recibió la cadena: %d %s %d\n", numeroRecibido1, caracterRecibido, numeroRecibido2);

        if (caracterRecibido[0] == '+')
        {
            resultado = numeroRecibido1 + numeroRecibido2;
            printf("%d + %d = %.1f\n", numeroRecibido1, numeroRecibido2, resultado);
        }
        else if (caracterRecibido[0] == '-')
        {
            if (numeroRecibido1 > numeroRecibido2)
            {
                resultado = numeroRecibido1 - numeroRecibido2;
                printf("%d - %d = %.1f\n", numeroRecibido1, numeroRecibido2, resultado);
            }
            else if (numeroRecibido1 < numeroRecibido2)
            {
                resultado = numeroRecibido2 - numeroRecibido1;
                printf("%d - %d = %.1f\n", numeroRecibido2, numeroRecibido1, resultado);
            }
            else
            {
                resultado = numeroRecibido1 - numeroRecibido2;
                printf("%d - %d = %.1f\n", numeroRecibido1, numeroRecibido2, resultado);
            }
        }
        else if (caracterRecibido[0] == '*')
        {
            resultado = numeroRecibido1 * numeroRecibido2;
            printf("%d * %d = %.1f\n", numeroRecibido1, numeroRecibido2, resultado);
        }
        else if (caracterRecibido[0] == '/')
        {
            if (numeroRecibido2 == 0)
            {
                perror("No se puede dividir entre 0");
            }
            else
            {
                resultado = numeroRecibido1 / numeroRecibido2;
                printf("%d / %d = %.1f\n", numeroRecibido1, numeroRecibido2, resultado);
            }
        }
        else
        {
            perror("El caracter pasado no es un signo matematico.");
            exit(EXIT_FAILURE);
        }

        close(fd[READ]);
        exit(resultado);
    }

    if (getpid() != 0)
    {
        int numeroEnviar1;
        int numeroEnviar2;
        char charEnviar[BUFFER];

        printf("Introduce el primer numero: \n");
        scanf("%d", &numeroEnviar1);
        printf("Introduce el operando: \n");
        scanf("%s", charEnviar);
        printf("Introduce el segundo numero: \n");
        scanf("%d", &numeroEnviar2);

        close(fd[READ]);
        write(fd[WRITE], &numeroEnviar1, sizeof(numeroEnviar1));
        write(fd[WRITE], &numeroEnviar2, sizeof(numeroEnviar2));
        write(fd[WRITE], &charEnviar, sizeof(charEnviar));
        close(fd[WRITE]);

        // Espero a que el hijo termine
        wait(NULL);
        printf("Proceso padre termino\n");
    }

    return 0;
}