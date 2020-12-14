#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    umask(0027);
    int fd;
    fd = open("ficherotest_2.txt", O_CREAT | O_TRUNC | O_RDWR, 0645);
    
    return 0;
}