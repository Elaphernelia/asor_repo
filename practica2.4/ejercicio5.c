#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    
    int pipe_1 = open("myfifo", O_NONBLOCK);
    int pipe_2 = open("myfifo_2", O_NONBLOCK);
     
    char buf[256];
    int cant;
    fd_set fds;

    FD_ZERO(&fds); 
    FD_SET(pipe_1, &fds);
    FD_SET(pipe_2, &fds);

    int maxfd = pipe_1 > pipe_2 ? pipe_1 : pipe_2;

    while(1 < 2){
        cant = select(maxfd + 1, &fds, NULL, NULL, NULL);

        if(cant == -1){
            perror("Error select");
        }

        else if(cant){

            if(FD_ISSET(pipe_1, &fds)){
                cant = read(pipe_1, buf, sizeof(buf));
                if (cant == 0){ 
                    if(close(pipe_1) == -1){
                        perror("Error close");
                    }

                    pipe_1 = open("myfifo", O_NONBLOCK);
                    break;
                }

                else if (cant > 0){ 
                    printf("Mensaje de myfifo: %s\n", buf);
                }
            }

            else if(FD_ISSET(pipe_2, &fds)){
                cant = read(pipe_2, buf, sizeof(buf));
                if (cant == 0){ 
                    if(close(pipe_2) == -1){
                        perror("Error close");
                    }

                    pipe_2 = open("myfifo_2", O_NONBLOCK);
                    break;
                }

                else if(cant > 0){ 
                    printf("Mensaje de myfifo_2: %s\n", buf);
                }
            }
        }
    }
  
    return 0;
}