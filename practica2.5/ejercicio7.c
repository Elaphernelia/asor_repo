#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <locale.h>


int main(int argc, char *argv[]){
    struct addrinfo hints;
    struct addrinfo* result;
    char buf_in[100];
    char buf_out[100];
    ssize_t car;
    

    memset(&hints, 0, sizeof(struct addrinfo));

    hints.ai_flags    = AI_PASSIVE;
    hints.ai_family   = AF_UNSPEC;  
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(argv[1], argv[2], &hints, &result) !=0){
        perror("ERROR\n");
    }

    int sd = socket(result->ai_family, result->ai_socktype, 0);

    if (sd == -1){
        perror("ERROR SOCKET\n");
    }

    if (connect(sd, (struct sockaddr *)result->ai_addr, result->ai_addrlen) == -1){
        perror("ERROR CONNECT\n");
    }

    while(1){
        car = read(0,buf_out, 99);
        if (car == -1){
            perror("ERROR READ\n");
        }
        buf_out[c] = '\0';

        if (buf_out[0] == 'Q'){
             if(close(sd) == -1){
                perror("ERROR CLOSE");
            }

            exit(0);
        }

        if (send(sd, buf_out, car, 0)==-1){
            perror("ERROR SEND\n");
        }

        car = recv(sd, buf_in, 99, 0);
        if (car == -1){
            perror("ERROR RECV\n");
        }
        buf_in[car] = '\0';

        printf("%s \n", buf_in);
    }

    if(close(sd) == -1){
        perror("ERROR CLOSE");
    }

    return 0;
}

