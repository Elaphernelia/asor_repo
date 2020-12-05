#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
    printf("UID real del usuario: %d\n", getuid());
    printf("EUID del usuario: %d\n", geteuid());
    /*Si el UID real y el EUID son iguales, podemos 
    dar por sentado que el bit setuid está activado.
    Si ponemos el comando ls -l /usr/bin/sudo vemos que los permisos 
    son ---s--x--x. Esa "s" sería una x normal si setuid no estuviera activado.
    */
    return 1;
}