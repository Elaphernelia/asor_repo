#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

    int fd;
    fd = open("ficherotest.txt", O_CREAT | O_TRUNC | O_RDWR, 0645);
    
    return 0;
}