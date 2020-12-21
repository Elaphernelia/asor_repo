#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>

int main(){

    int pid, p_pid, sid, p_gid, ch;
    char dire[50]; 

    pid = fork(); //demonio

    if (pid < 0){
    printf("Error fork\n");
    exit(1);
    }

    if (pid > 0){
    printf("ID proceso: %d\n", pid);
    exit(0);
    }

    sid = setsid();
    p_pid = getppid(); 
    p_gid = getpgid(pid);
    chdir("/tmp");

    if (getcwd(dire, 50)==NULL){perror("ERANGE.");}
    
    printf("ID proceso padre: %d\n", p_pid);
    printf("ID grupo de procesos: %d\n", p_gid);
    printf("ID de sesion: %d\n", sid);
    printf("directorio de trabajo: %s\n", dire);

    return 0;
}