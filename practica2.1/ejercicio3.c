#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


int main(int argc, char *argv[]) {
   int i; 
   for (i = 0; i < 255; i++){
        fprintf(stderr, "%s", strerror(i));
        printf ("\n");
    }
   
   return 1;
}