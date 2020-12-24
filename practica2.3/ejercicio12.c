#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int intcont = 0;
int tstpcont = 0; 
int cont = 0;

void fint(int signum){
    cont = cont + 1;
    intcont = intcont + 1;
}

void ftstp(int signum){
    cont = cont + 1;
    tstpcont = tstpcont + 1;
}

int main(int argc, char *argv[]){
    
    struct sigaction manint, mantstp;

    manint.sa_handler = fint;
    mantstp.sa_handler = ftstp;
    sigaction(SIGINT, &manint, NULL);
    sigaction(SIGTSTP, &mantstp, NULL);

    while(cont < 10){

    }
    printf("Int signals: %d \n", intcont);
    printf("Tstp signals: %d \n", tstpcont);

return 0;
}