#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int main (int argc, char *argv[]){

    if(argc < 4){
        printf("El numero de argumentos que has pasado es menor que tres. Tienes que ingresar el parametro operacion, y dos numeros.");
    }else{
        const char *operacion = argv[1];
        const char *num1_str = argv[2];
        const char *num2_str = argv[3];
        int resultado;
        int num1 = atoi(num1_str);
        int num2 = atoi(num2_str);

        if(strcmp(operacion, "suma") == 0){
            resultado = num1 + num2;
            printf("El resultado es: %d\n",resultado);
        }else if(strcmp(operacion, "resta") == 0){
            resultado = num1 - num2;
            printf("El resultado es: %d\n",resultado);
        }else if(strcmp(operacion, "multiplicacion") == 0) {
            resultado = num1 * num2;
            printf("El resultado es: %d\n",resultado);
        }else if(strcmp(operacion, "division") == 0){
            if(num2 == 0){
                printf("No se puede hacer una division entre cero.");
            }else{
                float resultadoDiv = (float)num1 / num2;
                printf("El resultado es: %.2f\n",resultadoDiv);
            }
        }
    }
}