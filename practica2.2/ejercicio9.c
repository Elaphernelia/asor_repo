#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

int main(){
//comprobamos la información del fichero creado en el ejercicio anterior
//ficherotest.txt
    struct stat buf;
    struct tm *tim;
    if (stat("ficherotest.txt", &buf) == -1) { perror("ERROR."); }
    printf("major: %d\n", major(buf.st_dev));
    printf("minor: %d\n", minor(buf.st_dev));
    printf("i-nodo: %d\n", buf.st_ino);
    printf("tipo: ");
    if (S_ISREG(buf.st_mode)){printf("fichero\n");}
    else if (S_ISDIR(buf.st_mode)){printf("directorio\n");}
    else if (S_ISLNK(buf.st_mode)){printf("enlace sim\n");}
    tim = localtime(&buf.st_atime);
    printf("ultimo acceso: %d : %d\n", tim->tm_hour, tim->tm_min);
    return 0;
}