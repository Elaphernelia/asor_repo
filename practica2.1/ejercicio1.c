#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


int main(int argc, char *argv[]) {
   if (setuid(0) == -1){
       perror("ERROR.");
   }
   return 1;
}
