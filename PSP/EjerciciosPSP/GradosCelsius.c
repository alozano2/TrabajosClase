#include <stdio.h>

int main (void){
    int tempCelsius;
    double temperaturaFar;

    printf("Introduce los grados Celsius que quieres convertir: ");
    scanf("%d", &tempCelsius);
    temperaturaFar = (tempCelsius*9/5) + 32;
    printf("%d grados Celsius, son %If grados Fahrenheit.",tempCelsius,temperaturaFar);

    return 0;
}