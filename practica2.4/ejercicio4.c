#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char *argv[]){
    
    //la tuberia con nombre que creamos en la terminal se llama myfifo
    int pipe = open("myfifo", 0222);

    if(pipe == -1){

        perror("Error open");
        _exit(0);
    }

    if(write(pipe, argv[1], strlen(argv[1])) == -1){

        perror("Error write");
    }

    return 0;
}