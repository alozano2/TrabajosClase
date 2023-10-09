#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


/*int esPrimo(int n){
    int primo = 1;
    int i = 2;

    while(primo && i < n/2){
        if(n%1 == 0){
            primo = 0;
        }
        i++;
    }
    return primo;
}*/


int main(void) {

    pid_t id_mi_hijo;
    pid_t que_pasa_si;

    id_mi_hijo = fork();
    que_pasa_si = fork();

   fprintf(stdout,"Hola soy el proceso %d mi hijo es %d y que pasa es %d,getpid"),id_mi_hijo,que_pasa_si;
   return 0;
}