#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

void signal1 (int señal){
    printf("Hola ");
}

void signal2 (int señal){
    printf("Mundo");
}

int main () {
    signal(SIGINT,signal1);
    signal(SIGUSR1, signal2);

    while(1){
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    return 0;
}