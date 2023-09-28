#include <stdio.h>
#include <string.h>

int main (){
    char cadena [30];
    int contador = 0;

    printf("Ingresa una frase:\n");
    fgets(cadena, sizeof(cadena),stdin);

    if(strlen(cadena) == 1){
        printf("Tienes que escribir una frase. Vuelve a introducirla.\n");
        fgets(cadena, sizeof(cadena),stdin);
    }

    for(int i = 0; i < strlen(cadena); i++){
        if(cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u'
        || cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] == 'I' || cadena[i] == 'O' || cadena[i] == 'U'){
            contador++;
        }
    }

    printf("La frase indicada tiene %d vocales.",contador);

    return 0;
}