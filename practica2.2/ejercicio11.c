#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

main(int argc, char *argv[]){
    struct stat buf;
    char nombrehard[50];
    char nombresym[50];
    if (stat(argv[1], &buf) == -1) { perror("ERROR."); }

    if (S_ISREG(buf.st_mode)){
        
        strcpy(nombrehard, argv[1]);
        strcpy(nombresym, argv[1]);

        if (link(argv[1], strcat(nombrehard, ".hard")) == -1){perror("LINK ERROR.");}

        if (symlink(argv[1], strcat(nombresym, ".sym")) == -1){perror("SYMLINK ERROR.");}

    }

    return 0;
}