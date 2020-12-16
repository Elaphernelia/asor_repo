#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    int fd;
    fd = open(argv[1], O_CREAT | O_TRUNC | O_RDWR, 0644);

    if (lockf(fd, F_TEST, 0)==0){
        if (lockf(fd, F_LOCK, 0) == 0){
            time_t tim;
             struct tm *localtim;
             if(time(&tim) != (time_t)-1){
                  localtim = localtime(&tim);
                  if(localtim != NULL){
                     printf("Hora: %d:%d\n", localtim->tm_hour, localtim->tm_min);

                     sleep(30);

                     if (lockf(fd, F_ULOCK, 0)== -1){
                         perror("ERROR.");
                     }
                  }
            }
        }
    }

    else{
        printf("BLOCKED \n");
    }

    return 0;
}