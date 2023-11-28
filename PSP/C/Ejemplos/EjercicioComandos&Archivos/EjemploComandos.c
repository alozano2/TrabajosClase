#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 100

// Prototipo de la función resultadoCalculadora
int resultadoCalculadora(int num1, int num2, char *operacion);
int sacarFichero(resultado);

int main(int argc, char *argv[]) {
    int num1;
    char *operacion;
    int num2;

    if (argc < 4) {
        printf("Por favor, debes ingresar al menos cuatro comandos:\n1. Nombre del archivo: %s\n2. Numero a sumar: %s\n3. Caracter de operacion matematica:%s\n4. Segundo numero a sumar: %s", argv[0], argv[1], argv[2], argv[3]);
        return 1;
    } else {
        num1 = atoi(argv[1]);
        operacion = argv[2];
        num2 = atoi(argv[3]);

        int resultado = resultadoCalculadora(num1, num2, operacion);
        if(sacarFichero(resultado) == 0){
            printf("El resultado se ha guardado correctamente en el archivo 'datos.txt'.\n");
        }else{
            perror("No ha sido posible abrir el archivo");
        }
    }

    return 0;
}

int resultadoCalculadora(int num1, int num2, char *operacion) {
    int resultado = 0;

    if (strcmp(operacion, "+") == 0) {
        resultado = num1 + num2;
        printf("%d + %d = %d\n", num1, num2, resultado);
    } else {
        printf("Operacion matematica no reconocida, debe ser suma, resta etc...");
    }
    return resultado;
}

/* A continuacion haremos que este mismo resultado, salga a un fichero en lugar de 
        por consola */

int sacarFichero (int resultado) {
    FILE* archivo = fopen ("datos.txt", "w");

    if(archivo == NULL){
        return 1;
    }
    
    fprintf(archivo, "El resultado es: %d", resultado);
    fclose(archivo);
    return 0;
}

/*Si quisiera leer del archivo se haria lo siguiente*/

int leerArchivo() {
    FILE* archivo = fopen("datos.txt", "r");
    char linea[MAX_BUFFER];

    if(archivo == NULL){
        return 1;
    }

    while(fgets(linea, sizeof(linea), archivo) != NULL){
        printf("%s", linea);
    }

    fclose(archivo);
    return 0;
}