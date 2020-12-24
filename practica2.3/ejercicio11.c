#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[]){

    int SLEEP_SECS;
    sigset_t x, y, z;
    sigemptyset(&x);
    sigemptyset(&z);
    sigaddset(&x, SIGINT);
    sigaddset(&x, SIGTSTP);
    sigaddset(&z, SIGTSTP);
    sigprocmask(SIG_BLOCK, &x, NULL);

    sleep(5);

    sigpending (&y);
    if (sigismember (&y, SIGINT)) {
        printf("sigint pending \n");
    }
    else if (sigismember (&y, SIGTSTP)) {
        printf("sigstp pending \n");
        sigprocmask(SIG_UNBLOCK, &z, NULL);
    }

return 0;
}