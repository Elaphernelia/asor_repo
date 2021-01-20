#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <locale.h>

#define NI_MAXHOST 1025
#define NI_MAXSERV 32

int main(int argc, char *argv[]){
    struct addrinfo hints;
    struct addrinfo* result;
    char buf[100];
    char host[NI_MAXHOST];
    char serv[NI_MAXSERV];
    socklen_t selen = sizeof(struct sockaddr_storage);
    

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    if (getaddrinfo(argv[1], argv[2], &hints, &result) !=0){
        perror("ERROR\n");
    }

    int sd = socket(result->ai_family, result->ai_socktype, 0);

    if (sd == -1){
        perror("ERROR SOCKET\n");
    }

    if (sendto(sd, argv[3], 1, 0, result->ai_addr, result->ai_addrlen)== -1){
        perror("ERROR SENDTO\n");
    }
    freeaddrinfo(result);//liberar memoria


    if (*argv[3] == 'd' || *argv[3] == 't'){
        int bytes = recvfrom(sd, buf, 100, 0, (struct sockaddr *) &argv, &selen);
        if (bytes==-1){
            perror("ERROR RECVFROM\n");
        }
        buf[bytes] = '\0';
        printf("%s\n%", buf);
    }

     if(close(sd) == -1){
        perror("ERROR CLOSE");
    }
   

    return 0;
}

