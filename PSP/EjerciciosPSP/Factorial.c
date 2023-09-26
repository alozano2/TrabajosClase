#include <stdio.h>

int main (void){
    int numero;
    int resultado = 1;

    printf("Calcular factorial.\n");
    printf("Introduce un numero: (no puede ser negativo)\n");
    scanf("%d",&numero);

    if(numero < 0){
        printf("El numero no puede ser negativo. Vuelve a introducirlo.\n");
        scanf("%d", &numero);
    }

    for(int i = 1; i <= numero; i++){
        resultado = i * resultado;
    }

    printf("El factorial del numero %d es: %d\n", numero, resultado);

    return 0;
}
