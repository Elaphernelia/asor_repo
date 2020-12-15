#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


 int main(int argc, char **argv){
    int fd;
    fd = open(argv[2], O_CREAT | O_TRUNC | O_RDWR, 0644);

    dup2(fd, 1);
    close(fd);
    printf("%s \n", argv[1]);
    
    return 0;
 }