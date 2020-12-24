#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

int alarmint = 0;

void falarm(int signum){
    alarmint = 1;
}

int main(int argc, char *argv[]){

    sigset_t x;
    struct sigaction mana;
    sigfillset(&x);
    sigdelset(&x, SIGALRM);
    sigdelset(&x, SIGUSR1);

    mana.sa_handler = falarm;
    sigaction(SIGALRM, &mana, NULL);

    int t = atoi(argv[1]);
    alarm(t);

    sigsuspend(&x);

    if (alarmint == 1){remove(argv[0]);}
    
    return 0;    
}