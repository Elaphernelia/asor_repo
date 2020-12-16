#include <stdio.h>
#include <time.h>
#include <locale.h>

int main(int argc, char *argv[]){
    time_t tim;
    struct tm *localtim;
    char s[500];
    setlocale(LC_ALL, "es_ES");
    if(time(&tim) != (time_t)-1){
        localtim = localtime(&tim);
        if (localtim != NULL){
            if (strftime(s, sizeof(s), "%A, %e de %B de %Y, %H:%M", localtim) != 0){
                printf("%s \n", s);
            }
        }
    }
    
    return 1;
}
