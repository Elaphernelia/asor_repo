#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(){
    int p_id, p_pid, p_gid, s_id;
    char dire[50]; 
    struct rlimit lim_;
     
    p_id = getpid();  
    p_pid = getppid(); 
    p_gid = getpgid(p_id);
    s_id = getsid(p_id);
    if (getcwd(dire, 50)==NULL){perror("ERANGE.");}
    if( getrlimit(RLIMIT_NPROC, &lim_) == 0) {
        
        printf("ID proceso: %d\n", p_id);
        printf("ID proceso padre: %d\n", p_pid);
        printf("ID grupo de procesos: %d\n", p_gid);
        printf("ID de sesion: %d\n", s_id);
        printf("directorio de trabajo: %s\n", dire);
        printf("limite de procesos: %ld\n", lim_.rlim_cur);
    }
    return 0;
}