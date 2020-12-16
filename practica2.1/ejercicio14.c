#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]){
    time_t tim;
    struct tm *localtim;
    if(time(&tim) != (time_t)-1){
        localtim = localtime(&tim);
        if(localtim != NULL){
        printf("Year: %d\n", localtim->tm_year + 1900);
        }
    }
    return 1;
}
