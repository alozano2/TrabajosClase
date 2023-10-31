#include <stdio.h>

int main (void){
    int numero;
    int contador = 0;

    printf("Calculadora de numeros primos.\n");
    printf("Introduce el numero que quieras comprobar:\n");
    scanf("%d",&numero);

    for(int i = 1; i <= numero; i++){
        if(numero%i == 0){
            contador++;
        }
    }

    if(contador == 2){
        printf("El numero %d es un numero primo\n",numero);
    }else{
        printf("El numero %d no es un numero primo\n", numero);
    }

    return 0;
}