#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    printf("Para el root filesystem: \n");
    printf ("Max num de enlaces al fichero: %ld \n", pathconf("/", _PC_LINK_MAX));
    printf ("Max num de bytes en un buffer de entrada: %ld \n", pathconf("/", _PC_MAX_INPUT));
    printf ("Longitud max de nombre para un fichero: %ld \n", pathconf("/", _PC_NAME_MAX));
    return 1;
}