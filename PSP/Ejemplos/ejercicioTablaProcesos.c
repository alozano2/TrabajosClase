#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
    int status;

    for(int i = 1; i <= 10; i++){
        pid_t idHijo;
        idHijo = fork();

        if(idHijo == 0){
            for (int j = 1; j <= 10; j++) {
                    int resultado = i * j;
                    printf("%d x %d = %d\n", i, j, resultado);
            }
            exit(0);
        }
    }

    for(int i = 1; i <= 10; i++){
            wait(&status);
    }

    return 0;
}