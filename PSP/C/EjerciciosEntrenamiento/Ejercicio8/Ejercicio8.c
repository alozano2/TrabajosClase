/*Crea un programa c que describa las ips que tiene en ordenador en linux*/

#include <stdio.h>
#include <unistd.h>

int main () {
    char *program = "ip";
    char *arguments [] = {"ip", "a", NULL};

    execvp(program, arguments);

    perror("execvp");
    return 1;
}