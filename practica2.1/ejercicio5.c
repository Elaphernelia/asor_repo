#include <sys/utsname.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

    struct utsname buf;
    if (uname(&buf) == 0){
        printf("Sistema operativo: %s \n", buf.sysname);
        printf("Host: %s \n", buf.nodename);
        printf("Release del sistema operativo: %s \n", buf.release);
        printf("Version del sistema operativo: %s \n", buf.version);
        printf("Hardware: %s \n", buf.machine);
    }
    return 1;
}