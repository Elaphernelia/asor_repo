#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
   /*Es más eficaz pasar los argumentos así:
   ./ejecuta "ps -el"
   */
   system(argv[1]);
   printf("El comando terminó de ejecutarse\n");

   return(0);
} 