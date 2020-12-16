#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, char *argv[]){
    printf("UID real del usuario: %d\n", getuid());
    printf("EUID del usuario: %d\n", geteuid());
    struct passwd *info = getpwuid(getuid());
    printf("Nombre del usuario: %s\n", info->pw_name);
    printf("Directorio home: %s\n", info->pw_dir);
    printf("Descripcion del usuario: %s\n", info->pw_name);
    return 1;
}
