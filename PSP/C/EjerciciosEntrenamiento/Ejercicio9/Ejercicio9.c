/*Crea un programa c que describa las ips que tiene en ordenador en Windows.*/

#include <stdio.h>
#include <unistd.h>

int main (){
    char *program = ("ipconfig");
    char *arguments [] = {"ipconfig", NULL};

    execvp(program, arguments);

    perror("execvp");
    return 1;
}