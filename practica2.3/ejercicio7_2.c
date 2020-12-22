#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h> 

int main (int argc, char *argv[]) {
   /*Es más eficaz pasar los argumentos así:
   ./ejecuta "ps -el"
   */
   execvp(argv[1],argv); 
   printf("El comando terminó de ejecutarse\n");

   return(0);
} 