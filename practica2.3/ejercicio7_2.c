#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h> 

int main (int argc, char *argv[]) {
   /*Es más eficaz pasar los argumentos así:
   ./ejecuta "ps -el"
   */
<<<<<<< HEAD
    int pid;
    int status;
    pid = fork(); 

    if (pid < 0){
        printf("Error fork\n");
        exit(1);
    }

    else if (pid == 0){
        if(execvp(argv[1], argv+1) == -1){perror("EXEC_ERROR");}
        
    }

    else if (pid > 0){
        int w = waitpid(pid, &status, WUNTRACED | WCONTINUED);
        if (w == -1) { perror("WAIT_ERROR"); exit(EXIT_FAILURE); }


        if (WIFEXITED(status)) {
           printf("El comando terminó de ejecutarse\n");
        }
    }
=======
   execvp(argv[1],argv); 
   printf("El comando terminó de ejecutarse\n");
>>>>>>> 075305ec2241f3b2c83ad4f162bbd9b16873c93e

   return(0);
} 