#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <netdb.h>
#include <locale.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

#define NI_MAXHOST 1025
#define NI_MAXSERV 32

static void fchild (int signum){ 
    wait(NULL);
}

int main(int argc, char *argv[]){
    struct addrinfo hints;
    struct addrinfo* result;
    char buf[100];

    //
    struct sigaction manchild;
    manchild.sa_handler = fchild;
    sigaction(SIGCHLD, &manchild, NULL);
    //
    

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

    if (bind(sd, result->ai_addr, result->ai_addrlen)!=0){
        perror("ERROR BIND\n");
    }

    freeaddrinfo(result);//liberar memoria
    listen(sd, 10);//10 = num max de conexiones en la cola de espera
    int client_sd;

    while(1){
        char host[NI_MAXHOST]; //constantes ya dadas
        char serv[NI_MAXSERV];

        struct sockaddr_storage client_addr;
        socklen_t client_addrlen = sizeof(client_addr);
        int c;

        client_sd = accept(sd, (struct sockaddr *) &client_addr, &client_addrlen);
        getnameinfo((struct sockaddr *)&client_addr, client_addrlen, host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST);
        printf("Conexión de %s:%s\n", host, serv);

        pid_t pid = fork();

        if (pid == 0){
            while (c = recv(client_sd, buf, 100, 0)){     
                buf[c] = '\0';
                send(client_sd, buf, c, 0);
            }
            printf("Conexion terminada de %s:%s\n", host, serv);
        }
        
        else{
            if(close(client_sd) == -1){
                perror("ERROR CLOSE");
            }
        }        
    }

     if(close(sd) == -1){
        perror("ERROR CLOSE");
    }


    return 0;
}