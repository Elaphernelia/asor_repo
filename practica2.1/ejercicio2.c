#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


int main(int argc, char *argv[]) {
   if (setuid(0) == -1){
       printf("ERROR.\n");
       fprintf(stderr, "%s", strerror(errno));
       printf ("\n");
       fprintf(stderr, "%d", errno);
       printf("\n");
   }
   return 1;
}