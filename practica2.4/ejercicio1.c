#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){

    int fd[2];

    pipe(fd);

    pid_t pid = fork(); 

    if (pid < 0){
    printf("Error fork\n");
    exit(1);
    }

    else if (pid == 0){
        if (dup2(fd[0], 0) == -1){ perror("DUP_ERROR");}
        close(fd[1]);
        close(fd[0]);
        if(execlp(argv[3], argv[3], argv[4], (char*) NULL)==-1){
            perror("EXEC_ERROR");
            exit(1);
        }
    exit(0);
    }

    else if(pid > 0){
        if (dup2(fd[1], 1) == -1){ perror("DUP_ERROR");}
        close(fd[0]);
        close(fd[1]);
        if(execlp(argv[1], argv[1], argv[2], (char*) NULL)==-1){
            perror("EXEC_ERROR");
            exit(1);
        }
        int status;
        waitpid(pid, &status, 0);
    }
    

return 0;
}