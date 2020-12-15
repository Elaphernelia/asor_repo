#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    int fd;
    fd = open(argv[2], O_CREAT | O_TRUNC | O_RDWR, 0644);

    if (lockf(fd, F_TEST, 0)==0){
        if (lockf(fd, F_LOCK, 0) == 0){
            
        }
    }

    else{
        printf("BLOCKED \n");
    }

    return 0;
}