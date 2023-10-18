#include <stdio.h>
#define buffer 100

int main() {
    //Abrimos el archivo en modo escritura
    FILE* archivo = fopen("datos.txt", "w");

    //Comprobamos si se pudo abrir
    if(archivo == NULL){
        perror("No se pudo abrir el archivo.");
        return 1;
    }

    //Escribimos en el archivo
    fprintf(archivo, "¿Hola que tal?\n");
    fprintf(archivo,"Esto es un texto de prueba para aprender a usar archivos.\n");

    //SIEMPRE cerramos el archivo
    fclose(archivo);

    //Para abrirlo en modo lectura
    archivo = fopen("datos.txt","r");

    //Comprobamos si se pudo abrir
    if(archivo == NULL){
        perror("No se pudo abrir el archivo");
        return 1;
    }

    printf("Leyendo el archivo:\n");
    char linea[buffer];

    while(fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
    }

    //Volvemos a cerrar el archivo
    fclose(archivo);

    return 0;
}