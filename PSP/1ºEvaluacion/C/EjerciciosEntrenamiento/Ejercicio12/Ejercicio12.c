#include <sys/types.h>
#include <stdlib.h> //Para poder poner EXIT_FAILURE
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> //Para incluir wait(NULL)
#include <signal.h> //Para trabajar con señales

#define NUMERO_PARAMETROS 3
int main (int argc, char *argv[]) {
    if(argc != NUMERO_PARAMETROS){
        printf("Debes ingresar dos parametros, ademas del nonbre del archivo. Parametros ingresados:%d",argc);
    }

    int LongitudNumsPrimos = atoi(argv[1]);
    int numeroProcesos = atoi(argv[2]);

    
}