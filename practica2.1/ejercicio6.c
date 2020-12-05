#include <unistd.h>
#include <limits.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    printf ("Longitud max de los argumentos: %d \n", sysconf(_SC_ARG_MAX));
    printf ("Num max de hijos: %d \n", sysconf(_SC_CHILD_MAX));
    printf ("Max numero de ficheros que un proceso puede mantener abiertos: %d \n", sysconf(_SC_OPEN_MAX));
    return 1;
}