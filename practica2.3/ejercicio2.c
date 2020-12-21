#include <sched.h>
#include <stdio.h>

int main(){
    int op;

    op = sched_getscheduler(0);
    switch(op){
        case SCHED_OTHER: printf("politica estandar\n");break;
        case SCHED_FIFO: printf("politica \n");break;
        case SCHED_RR: printf("politica round robin\n");break;
    }


    return 0;
}