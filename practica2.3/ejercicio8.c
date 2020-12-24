#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char *argv[]){

    int pid;
    int status;
    pid = fork(); //demonio

    if (pid < 0){
    printf("Error fork\n");
    exit(1);
    }

    else if (pid == 0){
    int pid, sid, p_pid, p_gid;

    pid = getpid();
    sid = setsid();
    p_pid = getppid(); 
    p_gid = getpgid(pid);
    chdir("/tmp");

    int fd_1 = open("/tmp/daemon.out", O_RDWR | O_CREAT | O_TRUNC, 0666);
    int fd_2 = open("/tmp/daemon.err", O_RDWR | O_CREAT | O_TRUNC, 0666);
    int fd_0 = open ("/dev/null", O_RDWR);

    if (dup2(fd_1, 1) == -1){ perror("DUP_ERROR");}
    if (dup2(fd_2, 2) == -1){ perror("DUP_ERROR");}
    if (dup2(fd_0, 0) == -1){ perror("DUP_ERROR");}

    if(execvp(argv[1], argv+1) == -1){
            perror("EXEC_ERROR");
            exit(1);
        }
    exit(0);
    }

    else if(pid > 0){
        int w = waitpid(pid, &status, WUNTRACED | WCONTINUED);
        if (w == -1) { perror("WAIT_ERROR"); exit(EXIT_FAILURE); }


        if (WIFEXITED(status)) {
           printf("El comando terminó de ejecutarse\n");
        }
    }
    
    return 0;

}