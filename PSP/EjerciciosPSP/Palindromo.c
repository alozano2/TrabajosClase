#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main () {
    char frase[40];
    int longitud;
    bool esPalindroma = true;

    printf("Ingresa una frase y te diré si es palíndroma.\n");
    fgets(frase, sizeof(frase),stdin);
    longitud = strlen(frase);

    //Convierto la frase a minusculas
    for(int i = 0; i < longitud; i++){
        frase[i] = tolower(frase[i]);
    }

    //Para quitar el caracter del final
    if (frase[longitud - 1] == '\n') {
        frase[longitud - 1] = '\0';
        longitud--;
    }

    
    for(int i = 0; i < longitud; i++){
        if(frase[i] != frase[longitud - 1 - i]){
            esPalindroma = false;
        }else{
            esPalindroma = true;
        }
    }

    if(esPalindroma){
        printf("La frase que has ingresado es palindroma");
    }else{
        printf("La clase que has ingresado no es palindroma.");
    }

    return 0;
}