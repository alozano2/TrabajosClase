#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t id_mi_hijo;

    int n = 42;
    double pi = 3.14;

    // clonacion
    id_mi_hijo = fork();

    //Hay dos procesos
    if(id_mi_hijo != 0) {
        // Padre
        printf ("Soy el padre %d, y mi hijo es %d\n",getpid(), id_mi_hijo);
        n = 1000;
        printf("N vale %d\n", n);
    }else{
        // Hijo
        printf("Soy el hijo %d, y mi hijo es %d\n", getpid(), id_mi_hijo);
        printf("N vale %d\n", n);
    }
    return 0;