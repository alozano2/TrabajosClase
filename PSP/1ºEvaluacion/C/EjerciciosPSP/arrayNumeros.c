#include <stdio.h>
#include <string.h>

int main (){
    int notas[5];
    //Para definir finals es 'const int' etc..
    printf("Ingresa las notas del alumno:\n");

    for(int i = 0; i < 5; i++){
        scanf("%d", &notas[i]);
    }

    double notaMedia;
    int notaAlta = notas[0];
    int notaBaja = notas[0];

    for(int i = 0; i < 5; i++){
        if(notas[i] > notaAlta){
            notaAlta = notas[i];
        }
        if(notas[i] < notaBaja){
            notaBaja = notas[i];
        }
        notaMedia = (notaMedia + notas[i]);

    }

    notaMedia = notaMedia / 5;

    printf("La nota mas alta es: %d\n", notaAlta);
    printf("La nota mas baja es: %d\n", notaBaja);
    printf("La nota media es: %f\n", notaMedia);
    printf("***************************************\n");

    for (int i = 0; i < 5; i++) {
        if(notas[i] >= 5){
            printf("Nota %d: %d ¡APROBADO!\n", (i + 1), notas[i]); 
        }else{
            printf("Nota %d: %d ¡SUSPENSO!\n", (i + 1), notas[i]); 
        }
    }

    return 0;
}