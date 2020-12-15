#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


 int main(int argc, char **argv){
    int fd;
    fd = open(argv[2], O_CREAT | O_TRUNC | O_RDWR, 0644);

    dup2(fd, 1);
    dup2(fd, 2);
    close(fd);
    printf("%s \n", argv[1]);
    perror("Mensaje de error.");
/*
Si hacemos ls > dirlist 2<&1, lo que hacemos es primero redirigir la
salida estándar a dirlist, y luego redirigir la salida de error
al mismo sitio donde va la salida estándar, que es dirlist.

En cambio, si hacemos ls 2> &1 > dirlist, redirigimos la salida
de error a la salida estándar, y luego hacemos que la salida estándar
vaya a dirlist.

Aunque sea similar, no es el mismo proceso, así que hay diferencia 
al usar estos operadores.
*/
    return 0;
 }